#pragma once

#include <baseex/core/export.hpp>
#include <baseex/core/CPathName.hpp>

#include <string>
#include <memory>
#include <vector>

namespace baseex {
namespace core {

class BASEEX_CORE_EXPORT CFileName
{
public:
    using Ptr = std::shared_ptr<CFileName>;

public:
    CFileName();
    CFileName(const std::wstring &aFullFileName);
    CFileName(const CPathName& aPath, const std::wstring &aFileName);

    CFileName& AddPath(const CPathName &aPath);
    CFileName& AddFileName(const CFileName &aFileName);

    std::wstring GetExtension() const;
    std::wstring GetName() const;
    std::wstring GetFileName() const;
    CPathName   GetPath() const;
    std::wstring GetFullFileName() const;

    void SetSeparator(std::wstring aSeparator);

private:
    std::wstring m_FileName;
    CPathName m_Path;
    mutable std::wstring m_FullFileName;
    std::wstring m_Separator;
};

}
}
