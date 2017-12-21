#pragma once

#include <baseex/core/export.hpp>
#include <baseex/version/version.hpp>

#include <memory>

namespace baseex {
namespace core {

//--------------------------------------------------------------
class ITimerPassive
{
public:
    using Ptr = std::shared_ptr<ITimerPassive>;

public:
    virtual ~ITimerPassive() = default;

    virtual bool Check() const = 0;
    virtual void Reset() = 0;
};
//--------------------------------------------------------------
BASEEX_CORE_EXPORT ITimerPassive::Ptr CreateTimerPassive(unsigned int aInterval);

}
}