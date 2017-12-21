#pragma once

#include <baseex/core/IFileObject.hpp>
#include <baseex/core/CPathName.hpp>

#include <vector>
#include <memory>

namespace baseex {
namespace core {

class BASEEX_CORE_EXPORT IDirectoryObject
{
public:
    using Ptr = std::shared_ptr<IDirectoryObject>;
    using ListPtr = std::shared_ptr<std::vector<Ptr>>;

public:
    virtual CPathName GetName() const = 0;

    virtual IDirectoryObject::ListPtr GetDirectories() const = 0;
    virtual IFileObject::ListPtr GetFiles() const = 0;
    virtual IFileObject::ListPtr GetFiles(std::wstring aMask) const = 0;
};

BASEEX_CORE_EXPORT IDirectoryObject::Ptr CreateDirectoryObject(const CPathName& aName);

}
}
