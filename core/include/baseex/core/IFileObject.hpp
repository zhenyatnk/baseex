#pragma once

#include <baseex/core/CFileName.hpp>

#include <vector>
#include <memory>

namespace baseex {
namespace core {

class BASEEX_CORE_EXPORT IFileObject
{
public:
    using Ptr = std::shared_ptr<IFileObject>;
    using ListPtr = std::shared_ptr<std::vector<Ptr>>;

public:
    virtual CFileName GetName() const = 0;
};

BASEEX_CORE_EXPORT IFileObject::Ptr CreateFileObject(const CFileName &aFileName);

}
}
