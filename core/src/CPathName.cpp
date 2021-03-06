#include <baseex/core/CPathName.hpp>
#include <baseex/core/Unicode.hpp>

#include <fstream>
#include <algorithm>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h>
#endif

namespace baseex {
namespace core {

//--------------------------------------------------------------------------------------------------------
CPathName::CPathName()
{
#ifdef _WIN32
    m_Separator = L"\\";
#else
    m_Separator = L"/";
#endif
}
CPathName::CPathName(const std::wstring& aPath)
{
#ifdef _WIN32
    m_Separator = L"\\";
#else
    m_Separator = L"/";
#endif
    std::wstring lPath = aPath;
    std::wstring lDirectory = L"";
    for (auto lSymbol : lPath)
    {
        if (lSymbol == L'\\' || lSymbol == L'/')
        {
            if (!lDirectory.empty() || m_Directories.empty() || m_Directories.back().empty())
                m_Directories.push_back(lDirectory);
            lDirectory = L"";
        }
        else
            lDirectory.push_back(lSymbol);
    }
    if (!lDirectory.empty())
        m_Directories.push_back(lDirectory);
}

CPathName& CPathName::AddPath(const std::wstring &aPath)
{
    std::wstring lPath = aPath;
    std::wstring lDirectory = L"";
    for (auto lSymbol : lPath)
    {
        if (lSymbol == L'\\' || lSymbol == L'/')
        {
            if (!lDirectory.empty() || m_Directories.empty())
                m_Directories.push_back(lDirectory);
            lDirectory = L"";
        }
        else
            lDirectory.push_back(lSymbol);
    }
    if (!lDirectory.empty())
        m_Directories.push_back(lDirectory);

    return *this;
}

CPathName& CPathName::AddPath(const CPathName &aPath)
{
    std::vector<std::wstring> lDirectories = aPath.GetDirectories();
    for (auto lDirectory : lDirectories)
        if (!lDirectory.empty())
            m_Directories.push_back(lDirectory);
    return *this;
}

std::wstring CPathName::ToString() const
{
    std::wstring lPath = L"";
    for (auto lDirectory : m_Directories)
        lPath += lDirectory + m_Separator;
    if (m_Directories.size() > 1)
        lPath = lPath.substr(0, lPath.size() - 1);
    return lPath;
}

std::vector<std::wstring> CPathName::GetDirectories() const
{
    return m_Directories;
}

void CPathName::SetSeparator(std::wstring aSeparator)
{
    m_Separator = aSeparator;
}

CPathName GetCurrentDirectory()
{
    if (auto answer = getcwd(nullptr, 0))
    {
        auto path = CPathName(convert(answer));
        free(answer);
        return path;
    }
    THROW_ERROR(exceptions::path_name_error, "Can't get curent directory!");
}
    
}
}
