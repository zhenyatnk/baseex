#pragma once

#include <baseex/core/IIterator.hpp>
#include <baseex/core/CFileName.hpp>
#include <baseex/core/IIteratorException.hpp>
#include <baseex/core/IStreamException.hpp>

#include <memory>
#include <string>
#include <vector>

namespace baseex {
namespace core {
	
class IStreamBuffer;

class IStream
    :public std::enable_shared_from_this<IStream>
{
public:
    using Ptr = std::shared_ptr<IStream>;

public:
    class Iterator
        :public TIterator<uint8_t, IBidirectionalNavigator>
    {
        friend IStream;
    public:
        explicit Iterator(IStream::Ptr aStream); 

        virtual void rewind() override;
        virtual bool is_valid() const override;
        virtual bool next() override;
        virtual bool prev() override;
        virtual uint8_t current() override;

    private:
        IStream::Ptr m_Stream;
        int m_Offset;
        bool m_IsRewind;
        size_t m_Size;
    };
	
public:
    virtual ~IStream() = default;

    virtual size_t Size() const = 0;

    virtual size_t                         Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const = 0;
    virtual std::shared_ptr<IStreamBuffer> Read(size_t aOffset, size_t aSize) const = 0;
    virtual size_t                         Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const = 0;
    virtual std::shared_ptr<IStreamBuffer> Read(const IStream::Iterator &aOffset, size_t aSize) const = 0;
    virtual size_t                         Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const = 0;
    virtual std::shared_ptr<IStreamBuffer> Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const = 0;
    virtual std::shared_ptr<IStreamBuffer> Read(const IStream::Iterator &aOffset) const = 0;
	
	IStream::Iterator CreateIterator()
    {
        return Iterator(shared_from_this());
    }
	
protected:
    int GetOffset(const IStream::Iterator &aIterator) const
    {
        return aIterator.m_Offset;
    }	
};

class IStreamBuffer
    :public IStream
{
public:
    using Ptr = std::shared_ptr<IStreamBuffer>;

public:
    virtual ~IStreamBuffer() = default;

    virtual const void* GetData() const = 0;

    template<class Type>
    Type GetBuff() const
    {
        return static_cast<Type>(GetData());
    }
    
    template<class Type>
    Type GetElement(uint64_t aElement) const
    {
        CHECK_THROW_BOOL((Size()/sizeof(Type) > aElement),
                         exceptions::stream_error, "Stream index out of bounds. Size stream='" + std::to_string(Size()/sizeof(Type)) + "' Requsted index='" + std::to_string(aElement) + "'.");
        return *(GetBuff<const Type*>() + aElement);
    }
};


class IStreamWriteBuffer
   :public IStreamBuffer
{
public:
    using Ptr = std::shared_ptr<IStreamWriteBuffer>;
	
public:
   virtual ~IStreamWriteBuffer() = default;

   virtual void* GetData() = 0;
};
//-------------------------------------------------------------------------------------
BASEEX_CORE_EXPORT IStreamBuffer::Ptr CreateStreamBuffer(const void* aBuff, const size_t &aSize);
BASEEX_CORE_EXPORT IStreamWriteBuffer::Ptr CreateStreamWriteBuffer(const void* aBuff, const size_t &aSize);
BASEEX_CORE_EXPORT IStreamWriteBuffer::Ptr CreateStreamWriteBuffer(const size_t &aSize);

BASEEX_CORE_EXPORT IStream::Ptr CreateStreamFile(const CFileName &aFilename);
BASEEX_CORE_EXPORT IStream::Ptr CreateStreamFileOpt(const CFileName &aFilename);

}
}
