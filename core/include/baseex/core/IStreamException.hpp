#pragma once

#include <baseex/core/export.hpp>
#include <baseex/core/BaseExceptions.hpp>

namespace baseex {
namespace core {
namespace exceptions {

class BASEEX_CORE_EXPORT stream_error
    :public exceptions_base::error_base
{
public:
    stream_error(const std::string &aMessage, const int &aErrorCode)
        :exceptions_base::error_base("IStream error: \'" + aMessage + "\'", aErrorCode)
    {}
};

}
}
}
