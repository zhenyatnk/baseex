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

class BASEEX_CORE_EXPORT ILinearStream
    :public std::enable_shared_from_this<ILinearStream>
{
public:
    typedef std::shared_ptr<ILinearStream> Ptr;

public:
    class Iterator
        :TIterator<uint8_t, IBidirectionalNavigator>
    {
        friend ILinearStream;
    public:
        explicit Iterator(ILinearStream::Ptr aStream);

        virtual void rewind() override;
        virtual bool is_valid() const override;
        virtual bool next() override;
        virtual bool prev() override;
        virtual uint8_t current() override;

    private:
        ILinearStream::Ptr m_Stream;
        int m_Offset;
        bool m_IsRewind;
        size_t m_Size;
    };

public:
    virtual ~ILinearStream() = default;

    virtual size_t Size() const = 0;
    virtual const void* GetBuff() const = 0;

    template<class Type>
    size_t Size() const
    {
        return Size() / sizeof(Type);
    }

    template<class Type>
    Type GetBuff() const
    {
        return static_cast<Type>(GetBuff());
    }

    template<class Type>
    Type GetElement(uint64_t aElement) const
    {
        CHECK_THROW_BOOL((Size<Type>() > aElement),
            exceptions::stream_error, "Stream index out of bounds. Size stream='" + std::to_string(Size<Type>()) + "' Requsted index='" + std::to_string(aElement) + "'.");
        return *(GetBuff<const Type*>() + aElement);
    }

    ILinearStream::Iterator CreateIterator()
    {
        return Iterator(shared_from_this());
    }

protected:
    int GetOffset(const ILinearStream::Iterator &aIterator) const
    {
        return aIterator.m_Offset;
    }
};

template<>
inline std::string ILinearStream::GetBuff() const
{
    return std::string(GetBuff<const char*>(), Size());
}

//-------------------------------------------------------------
class ILinearWriteStream
    :public ILinearStream
{
public:
    typedef std::shared_ptr<ILinearWriteStream> Ptr;

public:
    virtual ~ILinearWriteStream() = default;

    virtual void* GetBuff() = 0;

    template<class Type>
    Type GetBuff()
    {
        return static_cast<Type>(GetBuff());
    }
};

//-------------------------------------------------------------
class IStream
    :public std::enable_shared_from_this<IStream>
{
public:
    typedef std::shared_ptr<IStream> Ptr;

public:
    class Iterator
        :TIterator<uint8_t, IBidirectionalNavigator>
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
    virtual size_t Read(size_t Offset, uint8_t* buffer, size_t size) const = 0;
    virtual size_t Read(const IStream::Iterator &Offset, uint8_t* buffer, size_t size) const = 0;
    virtual size_t Read(const IStream::Iterator &Start, const IStream::Iterator &End, uint8_t* buffer) const = 0;

    virtual IStream::Ptr Read(size_t Offset, size_t size) const = 0;
    virtual IStream::Ptr Read(const IStream::Iterator &Offset, size_t size) const = 0;
    virtual IStream::Ptr Read(const IStream::Iterator &Start, const IStream::Iterator &End) const = 0;
    virtual IStream::Ptr Read(const IStream::Iterator &Offset) const = 0;

    template<class Type>
    size_t Size() const
    {
        return Size() / sizeof(Type);
    }

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

class IWriteStream
    :public virtual IStream
{
public:
    typedef std::shared_ptr<IWriteStream> Ptr;

public:
    virtual ~IWriteStream() = default;

    virtual void Write(size_t Offset, const uint8_t* buffer, size_t size) = 0;
    virtual void Write(size_t Offset, IStream::Ptr aStream) = 0;
};

//-------------------------------------------------------------------------------------
BASEEX_CORE_EXPORT IStream::Ptr CreateStreamBuffer(const void* aBuff, const size_t &aSize);
BASEEX_CORE_EXPORT IStream::Ptr CreateStreamBuffer(IStream::Ptr aStream);

BASEEX_CORE_EXPORT ILinearStream::Ptr CreateLinearBuffer(const void* aBuff, const size_t &aSize);
BASEEX_CORE_EXPORT ILinearStream::Ptr CreateLinearBuffer(IStream::Ptr aStream);

BASEEX_CORE_EXPORT ILinearWriteStream::Ptr CreateLinearWriteBuffer(const size_t &aSize);

namespace experimental {
	
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
}
