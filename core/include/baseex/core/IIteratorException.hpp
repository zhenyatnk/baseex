#pragma once

#include <baseex/core/export.hpp>
#include <baseex/core/BaseExceptions.hpp>
#include <string>

namespace baseex {
namespace core {
namespace exceptions {

class BASEEX_CORE_EXPORT iterator_error
    :public exceptions_base::error_base
{
public:
    iterator_error(const std::string &aMessage, const int &aErrorCode)
    :exceptions_base::error_base(std::string("Iterator error: \'") + aMessage + std::string("\'"), aErrorCode)
    {}
};

class BASEEX_CORE_EXPORT iterator_out_of_range_error
    :public iterator_error
{
public:
    iterator_out_of_range_error(const std::string &aMessage, const int &aErrorCode)
    :iterator_error(std::string("Position out of range ") + aMessage, aErrorCode)
    {}
};

class BASEEX_CORE_EXPORT iterator_invalid_position_error
    :public iterator_error
{
public:
    iterator_invalid_position_error(const std::string &aMessage, const int &aErrorCode)
    :iterator_error(std::string("Invalid position ") + aMessage, aErrorCode)
    {}
};

}
}
}
