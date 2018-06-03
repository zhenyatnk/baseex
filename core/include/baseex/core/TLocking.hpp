#pragma once

#include <baseex/version/version.hpp>
#include <mutex>
#include <utility>

namespace baseex {
namespace core {
    
template<class Type> class TLocking;

//--------------------------------------------------------------
template<>
class TLocking <void>
{
public:
    virtual ~TLocking() = default;
    
    virtual void lock()
    {
        m_Locker.lock();
    }
    virtual void unlock()
    {
        m_Locker.unlock();
    }
    
private:
    std::mutex m_Locker;
};

//--------------------------------------------------------------
template<class Type>
class TLocking
    :public Type, public TLocking<void>
{
public:
    TLocking() = default;

    TLocking(const Type& aRght)
        :Type(aRght)
    {}
    
    TLocking(Type&& aRght)
        :Type(std::move(aRght))
    {}
};
//--------------------------------------------------------------

}
}
