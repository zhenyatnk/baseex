#pragma once

#include <baseex/core/export.hpp>
#include <baseex/core/BaseExceptions.hpp>
#include <string>

namespace baseex {
namespace core {
namespace exceptions {

class BASEEX_CORE_EXPORT path_name_error
    :public exceptions_base::error_base
{
public:
    path_name_error(const std::string &aMessage, const int &aErrorCode)
        :exceptions_base::error_base(std::string("Path name error: \'") + aMessage + std::string("\'"), aErrorCode)
    {}
};

}
}
}
