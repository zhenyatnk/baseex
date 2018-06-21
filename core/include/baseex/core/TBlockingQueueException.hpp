#pragma once

#include <baseex/core/export.hpp>
#include <baseex/core/BaseExceptions.hpp>

namespace baseex {
namespace core {
namespace exceptions {
            
    class BASEEX_CORE_EXPORT blockingqueue_error
    :public exceptions_base::error_base
    {
    public:
        blockingqueue_error(const std::string &aMessage, const int &aErrorCode)
        :exceptions_base::error_base("System info error: \'" + aMessage + "\'", aErrorCode)
        {}
    };
    
    class BASEEX_CORE_EXPORT blockingqueue_closed_error
    :public blockingqueue_error
    {
    public:
        blockingqueue_closed_error(const std::string &aMessage, const int &aErrorCode)
        :blockingqueue_error("Queue closed: \'" + aMessage + "\'", aErrorCode)
        {}
    };
    
}
}
}
