#include <baseex/core/Unicode.hpp>
#include <codecvt>
#include <locale>

namespace baseex {
namespace core {

std::wstring convert(const std::string& aValue)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    return converterX.from_bytes(aValue);
}

std::string convert(const std::wstring& aValue)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    
    return converterX.to_bytes(aValue);
}

}
}
