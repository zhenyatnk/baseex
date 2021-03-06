#pragma once

#include <baseex/version/version.hpp>
#include <baseex/core/TNotifier.hpp>

#include <mutex>
#include <atomic>

namespace baseex {
namespace core {
//--------------------------------------------------------------
template<class Type> class TLockingShared;
    
template<>
class TLockingShared <void>
{
public:
    explicit TLockingShared()
    :m_SharedCount(0)
    {}
    
    virtual ~TLockingShared() = default;
    
    virtual void shared_lock()
    {
        std::lock_guard<std::mutex> lLock(m_ExclusiveLock);
        m_SharedCount++;
    }
    virtual void shared_unlock()
    {
        std::lock_guard<std::mutex> lLock(m_CountLock);
        if (!!m_SharedCount && !--m_SharedCount)
            m_SharedUnlock.notify_one();
    }
    
    virtual void lock()
    {
        m_ExclusiveLock.lock();
        std::lock_guard<std::mutex> lLock(m_CountLock);
        if(!!m_SharedCount)
            m_SharedUnlock.wait();
    }
    virtual void unlock()
    {
        m_ExclusiveLock.unlock();
    }
    
private:
    std::mutex m_ExclusiveLock;
    std::mutex m_CountLock;
    std::atomic_int m_SharedCount;
    TNotifier<void> m_SharedUnlock;
};

    
template<class Type>
class TLockingShared
    :public Type, public TLockingShared<void>
{
public:
    TLockingShared() = default;

    TLockingShared(Type&& aRght)
        :Type(std::move(aRght))
    {}

    TLockingShared(const Type& aRght)
        :Type(aRght)
    {}
};

//--------------------------------------------------------------
}
}
