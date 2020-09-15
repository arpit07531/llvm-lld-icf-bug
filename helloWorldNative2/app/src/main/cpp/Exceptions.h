//
// Created by araggarw on 9/1/2020.
//

#ifndef HELLOWORLDNATIVE2_EXCEPTIONS_H
#define HELLOWORLDNATIVE2_EXCEPTIONS_H

#endif //HELLOWORLDNATIVE2_EXCEPTIONS_H

#pragma once

#include <exception>
#include <string>


namespace CustomException
{


    class Exception
    {
    public:
        Exception(uint32_t tag) : m_tag(tag)
        {};

        uint32_t GetTag() const noexcept
        { return m_tag; }

        virtual unsigned int getErrorCode() const noexcept = 0;

        virtual std::string getDescription() const noexcept = 0;

    private:
        uint32_t m_tag;
    };


    template<class T>
    __attribute__((noinline))
    bool IsError(const std::exception_ptr &err) noexcept
    {
        if (!err)
        {
            return false;
        }

        try
        {
            std::rethrow_exception(err);
        }
        catch (const T &)
        {
            return true;
        }
        catch (...)
        {
            return false;
        }
    }

    struct Exception_Type1 : Exception
    {
        using Exception::Exception;

        unsigned int getErrorCode() const noexcept override
        { return 1; };

        std::string
        getDescription() const noexcept override
        { return "Exception_Type1"; }
    };


    struct Exception_Type2 : Exception
    {
        using Exception::Exception;

        unsigned int getErrorCode() const noexcept override
        { return 2; };

        std::string getDescription() const noexcept override
        {
            return "Exception_Type2";
        }
    };

    struct Exception_Type3 : Exception
    {
        using Exception::Exception;

        unsigned int getErrorCode() const noexcept override
        { return 3; };

        std::string
        getDescription() const noexcept override
        { return "Exception_Type3"; }
    };


} // namespace CustomException

