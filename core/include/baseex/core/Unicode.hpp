#pragma once

#include <baseex/core/export.hpp>

#include <string>

namespace baseex {
namespace core {

BASEEX_CORE_EXPORT std::string convert(const std::wstring&);
BASEEX_CORE_EXPORT std::wstring convert(const std::string&);

}
}