#pragma once
#include <baseex/core/export.hpp>
#include <baseex/core/TSingleton.hpp>
#include <baseex/core/ISystemInfoException.hpp>

#include <memory>

namespace baseex {
namespace core {
//------------------------------------------------------------------------------------
class IUsageCPU
{
public:
    using Ptr = std::shared_ptr<IUsageCPU>;

public:
    virtual ~IUsageCPU() = default;

    virtual float GetUsageCPU() const = 0;
};
//------------------------------------------------------------------------------------
class IUsageCPUProccess
{
public:
    using Ptr = std::shared_ptr<IUsageCPUProccess>;

public:
    virtual ~IUsageCPUProccess() = default;

    virtual float GetUsageCPUProccess() const = 0;
};
//------------------------------------------------------------------------------------
class ISystemInfo
    :public IUsageCPU, public IUsageCPUProccess
{
public:
    using Ptr = std::shared_ptr<ISystemInfo>;

public:
    virtual ~ISystemInfo() = default;
};

//------------------------------------------------------------------------------------
BASEEX_CORE_EXPORT ISystemInfo::Ptr CreateSystemInfo();

SINGLETON_NAME(ISystemInfo::Ptr, CreateSystemInfo(), SystemInfoGlobal);
//------------------------------------------------------------------------------------
}
}
