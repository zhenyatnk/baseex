#pragma once

#include <baseex/core/TBlockingQueueException.hpp>

#include <mutex>
#include <string>
#include <queue>

namespace baseex {
namespace core {
    
namespace {
namespace detail{

template < typename T > struct is_begin
{
    template < typename U >
    static char test( U&&, decltype( std::begin( std::declval<U>() ) )* = 0 ) ;

    using two_chars = char[2] ; static two_chars& test(...) ;

    static constexpr bool value = sizeof( test( std::declval<T>() ) ) == 1 ;
};
    
};
template < typename T > struct is_container :
    std::conditional< detail::is_begin<T>::value || std::is_array<T>::value,
    std::true_type, std::false_type >::type {};
};
    
template<typename Message>
class TBlockingQueue
{
public:
    ~TBlockingQueue()
    {
    }
    
    template<typename T, typename std::enable_if<!is_container<T>::value>::type* = nullptr>
    void Push(T&& message)
    {
        {
            std::lock_guard<std::mutex> lock(m_lock);
            m_queue.push(std::forward<T>(message));
        }
        m_pushed.notify_all();
    }
    
    template<typename Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr>
    void Push(Container messages)
    {
        {
            std::lock_guard<std::mutex> lock(m_lock);
            for(auto&& message: messages)
                m_queue.push(std::move(message));
        }
        m_pushed.notify_all();
    }
    
    void Push(std::queue<Message> messages)
    {
        {
            std::lock_guard<std::mutex> lock(m_lock);
            while(!messages.empty())
            {
                m_queue.push(std::move(messages.front()));
                messages.pop();
            }
        }
        m_pushed.notify_all();
    }
    
    bool GetContainer(std::vector<Message>& messages)
    {
        std::unique_lock<std::mutex> lock(m_lock);
        m_pushed.wait(lock, [this]() { return m_closing || !m_queue.empty(); });
        
        if(m_closing)
            return false;
        
        messages.clear();
        messages.reserve(m_queue.size());
        while(!m_queue.empty())
        {
            messages.push_back(std::move(m_queue.front()));
            m_queue.pop();
        }
        return true;
    }
    
    std::vector<Message> GetContainer()
    {
        std::vector<Message> messages;
        CHECK_THROW_BOOL(GetContainer(messages), exceptions::blockingqueue_closed_error, "");
        return messages;
    }

    bool GetContainer(size_t count, std::vector<Message>& messages)
    {
        std::unique_lock<std::mutex> lock(m_lock);
        m_pushed.wait(lock, [this]() { return m_closing || !m_queue.empty(); });
        
        if(m_closing)
            return false;

        messages.clear();
        messages.reserve(m_queue.size());
        while(!m_queue.empty() && count--)
        {
            messages.push_back(std::move(m_queue.front()));
            m_queue.pop();
        }
        return true;
    }
    
    std::vector<Message> GetContainer(size_t count)
    {
        std::vector<Message> messages;
        CHECK_THROW_BOOL(GetContainer(count, messages), exceptions::blockingqueue_closed_error, "");
        return messages;
    }
    
    bool Get(Message& message)
    {
        std::unique_lock<std::mutex> lock(m_lock);
        m_pushed.wait(lock, [this]() { return m_closing || !m_queue.empty(); });
        
        if(m_closing)
            return false;

        message = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }
    
    Message Get()
    {
        Message message;
        CHECK_THROW_BOOL(Get(message), exceptions::blockingqueue_closed_error, "");
        return message;
    }
    
    size_t Size()
    {
        std::lock_guard<std::mutex> lock(m_lock);
        m_queue.size();
    }
    
    void Close()
    {
        {
            std::lock_guard<std::mutex> lock(m_lock);
            m_closing = true;
        }
        m_pushed.notify_all();
    }
    
private:
    bool m_closing = false;
    std::queue<Message> m_queue;
    std::condition_variable m_pushed;
    std::mutex m_lock;
};
    
}
}
