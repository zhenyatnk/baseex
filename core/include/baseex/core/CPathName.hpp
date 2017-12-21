#pragma once

#include <baseex/core/export.hpp>

#include <string>
#include <memory>
#include <vector>

namespace baseex {
namespace core {

class BASEEX_CORE_EXPORT CPathName
{
public:
    using Ptr = std::shared_ptr<CPathName>;

public:
    CPathName();
    CPathName(const std::wstring &aPath);

    CPathName& AddPath(const std::wstring &aPath);
    CPathName& AddPath(const CPathName &aPath);

    std::wstring ToString() const;
    std::vector<std::wstring> GetDirectories() const;

    void SetSeparator(std::wstring aSeparator);

private:
    std::vector<std::wstring> m_Directories;
    std::wstring m_Separator;
};

}
}
