#pragma once

#include <baseex/core/export.hpp>
#include <stdexcept>
#include <string>

namespace baseex {
namespace core {
namespace exceptions_base {

#ifdef _WIN32
    #define __CROSS_FILE__ __FILE__
    #define __CROSS_LINE__ __LINE__
    #define __CROSS_FUNCTION__ __FUNCSIG__
#elif __APPLE__
    #define __CROSS_FILE__ __FILE__
    #define __CROSS_LINE__ __LINE__
    #define __CROSS_FUNCTION__ __PRETTY_FUNCTION__
#elif __linux__
    #define __CROSS_FILE__ __FILE__
    #define __CROSS_LINE__ __LINE__
    #define __CROSS_FUNCTION__ __PRETTY_FUNCTION__
#else
#   error "Unknown compiler"
#endif
    
#define __FULL_FUNCTION_NAME__ std::string(" File:") + std::string(__CROSS_FILE__) + std::string(":") + std::to_string(__CROSS_LINE__) + std::string(" Function:\"") + std::string(__CROSS_FUNCTION__) + std::string("\"")
    
#define ERR_UNKNOWN   0xFFFFFFFF

#define THROW_ERROR_BY_CODE(error, type_exception, message) throw type_exception(message + __FULL_FUNCTION_NAME__, error)
#define THROW_ERROR_BY_CODE2(error, type_exception, message1, message2) throw type_exception(message1 + __FULL_FUNCTION_NAME__, message2, error)
#define THROW_ERROR_BY_CODE3(error, type_exception, message1, message2, message3) throw type_exception(message1 + __FULL_FUNCTION_NAME__, message2, message3, error)
#define THROW_ERROR(type_exception, message) THROW_ERROR_BY_CODE(ERR_UNKNOWN, type_exception, message)
#define THROW_ERROR2(type_exception, message1, message2) THROW_ERROR_BY_CODE2(ERR_UNKNOWN, type_exception, message1, message2)
#define THROW_ERROR3(type_exception, message1, message2, message3) THROW_ERROR_BY_CODE3(ERR_UNKNOWN, type_exception, message1, message2, message3)

#define CHECK_THROW_BOOL(cond, type_exception, message) {bool ResCond = cond; if(!ResCond) {THROW_ERROR(type_exception,message);}}
#define CHECK_THROW_ERR(error, type_exception, message) {int ECode = error; if(!BASE_SUCCESS(ECode)) {THROW_ERROR_BY_CODE(ECode,type_exception,message);}}
#define CHECK_THROW_OTHER_ERR(error, code_ok, type_exception, message) {int ECode = error; if(ECode != (code_ok)) {THROW_ERROR_BY_CODE(ECode,type_exception,message);}}

#define CATCH_MESSAGE_CODE_ERROR(type_exception, message, HandlerError) catch(type_exception &ex){ HandlerError((message + std::string("\n") + ex.what()), ex.GetErrorCode()); }

#define CATCH_CODE_ERROR(type_exception, HandlerError) catch(type_exception &ex){ HandlerError(ex.what(), ex.GetErrorCode()); }
#define CATCH_ERROR(type_exception, HandlerError) catch(type_exception &ex){ HandlerError(ex.what(), ERR_UNKNOWN); }

class BASEEX_CORE_EXPORT error_base
    :public std::runtime_error
{
public:
    error_base(const std::string &aMessage, const int &aErrorCode)
        :runtime_error(aMessage), m_ErrorCode(aErrorCode)
    {}

    int GetErrorCode() const
    {
        return m_ErrorCode;
    }

private:
    int m_ErrorCode;
};
}
    
namespace exceptions{
class BASEEX_CORE_EXPORT not_implemented_error
    :public exceptions_base::error_base
{
public:
    not_implemented_error(const std::string &aMessage, const int &aErrorCode)
        :exceptions_base::error_base("Not implemented error: \'" + aMessage + "\'", aErrorCode)
    {}
};
    
}
}
}
