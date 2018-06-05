#include <baseex/core/ISystemInfo.hpp>

#ifdef __APPLE__

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

namespace baseex {
namespace core {
//-----------------------------------------
class CGetterUsageCPU
    :public IUsageCPU
{
public:
    CGetterUsageCPU();

    CGetterUsageCPU(const CGetterUsageCPU&) = delete;
    CGetterUsageCPU& operator=(const CGetterUsageCPU&) = delete;

    virtual float GetUsageCPU() const override;

private:
};

CGetterUsageCPU::CGetterUsageCPU()
{
}

float CGetterUsageCPU::GetUsageCPU() const
{
    THROW_ERROR(exceptions::not_implemented_error, "CGetterUsageCPU::GetUsageCPU, for MacOS");
}
//-----------------------------------------
class CGetterUsageCPUProccess
    :public IUsageCPUProccess
{
public:
    CGetterUsageCPUProccess();

    CGetterUsageCPUProccess(const CGetterUsageCPUProccess&) = delete;
    CGetterUsageCPUProccess& operator=(const CGetterUsageCPUProccess&) = delete;

    virtual float GetUsageCPUProccess() const override;
    
protected:
    float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks) const;
    
private:
    mutable long long m_previousTotalTicks;
    mutable long long m_previousIdleTicks;
};
    
CGetterUsageCPUProccess::CGetterUsageCPUProccess()
    :m_previousTotalTicks(0), m_previousIdleTicks(0)
{
}

float CGetterUsageCPUProccess::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks) const
{
    unsigned long long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
    unsigned long long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;
    float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
    m_previousTotalTicks = totalTicks;
    m_previousIdleTicks  = idleTicks;
    return ret;
}

float CGetterUsageCPUProccess::GetUsageCPUProccess() const
{
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    CHECK_THROW_BOOL(KERN_SUCCESS == host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count), exceptions::system_info_error, "GetUsageCPUProccess cannot get host_statistics");
    unsigned long long totalTicks = 0;
    for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
    return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks) * 100;
}
//-----------------------------------------
class CSystemInfo
    :public ISystemInfo
{
public:
    virtual float GetUsageCPU() const override;
    virtual float GetUsageCPUProccess() const override;

private:
    CGetterUsageCPU m_CPU;
    CGetterUsageCPUProccess m_CPUByProccess;
};

float CSystemInfo::GetUsageCPU() const
{
    return m_CPU.GetUsageCPU();
}

float CSystemInfo::GetUsageCPUProccess() const
{
    return m_CPUByProccess.GetUsageCPUProccess();
}

ISystemInfo::Ptr CreateSystemInfo()
{
    return std::make_shared<CSystemInfo>();
}

}
}

#endif
