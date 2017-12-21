#pragma once

#include <baseex/core/export.hpp>
#include <baseex/core/ISystemInfo.hpp>

#include <memory>

namespace baseex {
namespace core {

class IStrategyExpansion
{
public:
    using Ptr = std::shared_ptr<IStrategyExpansion>;

public:
    virtual ~IStrategyExpansion() = default;

    virtual int8_t GetOptimalDiffWorkers(unsigned int aCountUnworkingTasks, unsigned int aCountExistsThreads) const = 0;
};

BASEEX_CORE_EXPORT IStrategyExpansion::Ptr CreateExpansionToMax(unsigned int aCountMaxThread);
BASEEX_CORE_EXPORT IStrategyExpansion::Ptr CreateExpansionToCPU(IUsageCPU::Ptr aUsageCPU, uint8_t aMaxUsageCPU, unsigned int aCountMinThread);
BASEEX_CORE_EXPORT IStrategyExpansion::Ptr CreateExpansionToCPUByProccess(IUsageCPUProccess::Ptr aUsageCPUProccess, uint8_t aMaxUsageCPU, unsigned int aCountMinThread);

}
}