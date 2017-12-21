#pragma once

#include <baseex/core/ITimerActiveObserver.hpp>
#include <baseex/version/version.hpp>

#include <memory>

namespace baseex {
namespace core {

//--------------------------------------------------------------
class ITimerActive
   :public virtual IObservableTimer
{
public:
    using Ptr = std::shared_ptr<ITimerActive>;

public:
    virtual ~ITimerActive() = default;
};
//--------------------------------------------------------------
BASEEX_CORE_EXPORT ITimerActive::Ptr CreateTimerActive(unsigned int aInterval);
BASEEX_CORE_EXPORT ITimerActive::Ptr CreateTimerActive(unsigned int aInterval, unsigned int aCountRepeat);

}
}