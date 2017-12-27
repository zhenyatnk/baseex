#include <baseex/core/IStream.hpp>

#include <cstring>
#include <cstdlib>

namespace baseex {
namespace core {

class CStreamLinear
    :public ILinearStream
{
public:
    CStreamLinear(IStream::Ptr aStream);
    CStreamLinear(const void* aBuff, size_t aSize);
    ~CStreamLinear();

    virtual size_t Size() const override;
    virtual const void* GetBuff() const override;

private:
    void* m_Buff;
    size_t m_Size;
};

CStreamLinear::CStreamLinear(IStream::Ptr aStream)
    :m_Size(aStream->Size())
{
    m_Buff = malloc(m_Size);
    aStream->Read(0, (uint8_t*)m_Buff, m_Size);
}

CStreamLinear::CStreamLinear(const void* aBuff, size_t aSize)
    :m_Size(aSize)
{
    m_Buff = malloc(m_Size);
    memcpy(m_Buff, aBuff, m_Size);
}

CStreamLinear::~CStreamLinear()
{
    free(m_Buff);
}

size_t CStreamLinear::Size() const
{
    return m_Size;
}

const void* CStreamLinear::GetBuff() const
{
    return m_Buff;
}

ILinearStream::Ptr CreateLinearBuffer(const void* aBuff, const size_t &aSize)
{
    return ILinearStream::Ptr(new CStreamLinear(aBuff, aSize));
}
ILinearStream::Ptr CreateLinearBuffer(IStream::Ptr aStream)
{
    return ILinearStream::Ptr(new CStreamLinear(aStream));
}
//---------------------------------------------------------------------------------------
class CStreamLinearWrite
    :public ILinearWriteStream
{
public:
    CStreamLinearWrite(size_t aSize);
    ~CStreamLinearWrite();

    virtual size_t Size() const override;
    virtual const void* GetBuff() const override;
    virtual void* GetBuff() override;

private:
    void* m_Buff;
    size_t m_Size;
};

CStreamLinearWrite::CStreamLinearWrite(size_t aSize)
    :m_Size(aSize)
{
    m_Buff = malloc(m_Size);
    memset(m_Buff, 0, m_Size);
}

CStreamLinearWrite::~CStreamLinearWrite()
{
    free(m_Buff);
}

size_t CStreamLinearWrite::Size() const
{
    return m_Size;
}

const void* CStreamLinearWrite::GetBuff() const
{
    return m_Buff;
}

void* CStreamLinearWrite::GetBuff()
{
    return m_Buff;
}

ILinearWriteStream::Ptr CreateLinearWriteBuffer(const size_t &aSize)
{
    return ILinearWriteStream::Ptr(new CStreamLinearWrite(aSize));
}
//---------------------------------------------------------------------------------------
class CStreamBuffer
    :public IStream
{
public:
    CStreamBuffer(IStream::Ptr aStream);
    CStreamBuffer(const void* aBuff, size_t aSize);
    ~CStreamBuffer();

    virtual size_t Size() const override;
    virtual size_t Read(size_t Offset, uint8_t* buffer, size_t size) const override;
    virtual size_t Read(const IStream::Iterator &Offset, uint8_t* buffer, size_t size) const override;
    virtual size_t Read(const IStream::Iterator &Start, const IStream::Iterator &End, uint8_t* buffer) const override;
    virtual IStream::Ptr Read(size_t Offset, size_t size) const override;
    virtual IStream::Ptr Read(const IStream::Iterator &Offset, size_t size) const override;
    virtual IStream::Ptr Read(const IStream::Iterator &Start, const IStream::Iterator &End) const override;
    virtual IStream::Ptr Read(const IStream::Iterator &Offset) const override;

private:
    void* m_Buff;
    size_t m_Size;
};

CStreamBuffer::CStreamBuffer(IStream::Ptr aStream)
    :m_Size(aStream->Size())
{
    m_Buff = malloc(m_Size);
    aStream->Read(0, (uint8_t*)m_Buff, m_Size);
}

CStreamBuffer::CStreamBuffer(const void* aBuff, size_t aSize)
    :m_Size(aSize)
{
    m_Buff = malloc(m_Size);
    memcpy(m_Buff, aBuff, m_Size);
}

CStreamBuffer::~CStreamBuffer()
{
    free(m_Buff);
}

size_t CStreamBuffer::Size() const
{
    return m_Size;
}

size_t CStreamBuffer::Read(size_t Offset, uint8_t* buffer, size_t size) const
{
    size_t lReadSize = 0;
    if (m_Size > Offset)
    {
        lReadSize = size;
        if (!!lReadSize && (Offset + lReadSize) > m_Size)
            lReadSize = m_Size - Offset;
        memcpy(buffer, (char*)m_Buff + Offset, lReadSize);
    }
    return lReadSize;
}

IStream::Ptr CStreamBuffer::Read(size_t Offset, size_t size) const
{
    IStream::Ptr lStreamBuffer;
    if (m_Size > Offset)
    {
        if (Offset + size > m_Size)
            size = m_Size - Offset;
        lStreamBuffer = CreateStreamBuffer((void*)((char*)m_Buff + Offset), size);
    }
    return lStreamBuffer;
}

size_t CStreamBuffer::Read(const IStream::Iterator &Offset, uint8_t* buffer, size_t size) const
{
    if (!Offset.is_valid())
        return 0;
    return Read(this->GetOffset(Offset), buffer, size);
}

size_t CStreamBuffer::Read(const IStream::Iterator &Start, const IStream::Iterator &End, uint8_t* buffer) const
{
    if (!Start.is_valid() || !End.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(Start);
    size_t end_offset = this->GetOffset(End);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, buffer, (end_offset - start_offset) + 1);
}

IStream::Ptr CStreamBuffer::Read(const IStream::Iterator &Offset, size_t size) const
{
    if (!Offset.is_valid())
        return nullptr;
    return Read(this->GetOffset(Offset), size);
}

IStream::Ptr CStreamBuffer::Read(const IStream::Iterator &Start, const IStream::Iterator &End) const
{
    if (!Start.is_valid() || !End.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(Start);
    size_t end_offset = this->GetOffset(End);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, (end_offset - start_offset) + 1);
}

IStream::Ptr CStreamBuffer::Read(const IStream::Iterator &Offset) const
{
    IStream::Ptr lStreamBuffer;
    if (Offset.is_valid())
    {
        auto offset = this->GetOffset(Offset);
        if (offset < m_Size)
            lStreamBuffer = Read(offset, m_Size - offset);
    }
    return lStreamBuffer;
}

IStream::Ptr CreateStreamBuffer(const void* aBuff, const size_t &aSize)
{
    return IStream::Ptr(new CStreamBuffer(aBuff, aSize));
}
IStream::Ptr CreateStreamBuffer(IStream::Ptr aStream)
{
    return IStream::Ptr(new CStreamBuffer(aStream));
}
//-------------------------------------------------------------------------------------

}
}
