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

void test1()
{
    std::exception_ptr ptr = std::make_exception_ptr(CustomException::Exception_Type2{0x02});
    handleException(ptr);
}

void test2()
{
    std::exception_ptr ptr = std::make_exception_ptr(CustomException::Exception_Type3{0x02});
    handleException(ptr);
}

void test3()
{
    std::exception_ptr ptr = std::make_exception_ptr(CustomException::Exception_Type1{0x01});
    handleException(ptr);
}


extern "C" JNIEXPORT jstring

JNICALL
Java_com_utils_helloworldnative2_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */)
{
    std::string hello = "Hello from C++ ";
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Inside JNI");

    test1();
    test2();
    test3();
    return env->NewStringUTF(hello.c_str());
}



