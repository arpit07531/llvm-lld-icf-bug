#include <jni.h>
#include <string>
#include "Exceptions.h"
#include <android/log.h>

static const char *LOG_TAG = "ARPIT";

void handleException(std::exception_ptr &ptr)
{
    if (CustomException::IsError<CustomException::Exception_Type2>(ptr))
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "exception type is Exception_Type2 ");
    }
    else if (CustomException::IsError<CustomException::Exception_Type3>(ptr))
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "exception type is Exception_Type3 ");
    }
    else if (CustomException::IsError<CustomException::Exception_Type1>(ptr))
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "exception type is Exception_Type1 ");
    }
    else
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Unknown exception type");
    }
}

extern "C" JNIEXPORT jstring

JNICALL
Java_com_utils_helloworldnative2_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */)
{
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Inside JNI");

    bool result1 = CustomException::IsError<CustomException::Exception_Type2>(std::make_exception_ptr(CustomException::Exception_Type1{0x01}));
    bool result2 = CustomException::IsError<CustomException::Exception_Type2>(std::make_exception_ptr(CustomException::Exception_Type2{0x02}));
    bool result3 = CustomException::IsError<CustomException::Exception_Type2>(std::make_exception_ptr(CustomException::Exception_Type3{0x03}));

    std::string result = "";
    result = result + "CustomException::Exception_Type1" + " : " + (result1 ? "true" : "false") + "\n";
    result = result + "CustomException::Exception_Type2" + " : " + (result2 ? "true" : "false") + "\n";
    result = result + "CustomException::Exception_Type3" + " : " + (result3 ? "true" : "false") + "\n";

    return env->NewStringUTF(result.c_str());
}



