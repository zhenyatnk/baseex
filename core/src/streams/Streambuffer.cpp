#include <baseex/core/IStream.hpp>

#include <cstring>
#include <cstdlib>

namespace baseex {
namespace core {

class CStreamBuffer
    :public IStreamWriteBuffer
{

public:
    explicit CStreamBuffer(const size_t &aSize);
    CStreamBuffer(const void* aBuff, const size_t &aSize);
    ~CStreamBuffer();

    //IStream
    virtual size_t Size() const override;

    virtual size_t             Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const override;
    virtual IStreamBuffer::Ptr Read(size_t aOffset, size_t aSize) const override;
    virtual size_t             Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset, size_t aSize) const override;
    virtual size_t             Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset) const override;

    //IStreamBuffer
    virtual const void* GetData() const override;

    //IStreamWriteBuffer
    virtual void* GetData() override;

private:
    void* m_Buff;
    size_t m_Size;
};

CStreamBuffer::CStreamBuffer(const size_t &aSize)
    :m_Size(aSize)
{
    m_Buff = malloc(m_Size);
    memset(m_Buff, 0, m_Size);
}

CStreamBuffer::CStreamBuffer(const void* aBuff, const size_t &aSize)
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

size_t CStreamBuffer::Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const
{
    size_t lReadSize = 0;
    if (m_Size > aOffset)
    {
        lReadSize = aSize;
        if (!!lReadSize && (aOffset + lReadSize) > m_Size)
            lReadSize = m_Size - aOffset;
        memcpy(aBuffer, (char*)m_Buff + aOffset, lReadSize);
    }
    return lReadSize;
}

IStreamBuffer::Ptr CStreamBuffer::Read(size_t aOffset, size_t aSize) const
{
    IStreamBuffer::Ptr lStreamBuffer;
    if (m_Size > aOffset)
    {
        if (aOffset + aSize > m_Size)
            aSize = m_Size - aOffset;
        lStreamBuffer = CreateStreamBuffer((void*)((char*)m_Buff + aOffset), aSize);
    }
    return lStreamBuffer;
}

size_t CStreamBuffer::Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const
{
    if (!aOffset.is_valid())
        return 0;
    return Read(this->GetOffset(aOffset), aBuffer, aSize);
}

IStreamBuffer::Ptr CStreamBuffer::Read(const IStream::Iterator &aOffset, size_t aSize) const
{
    if (!aOffset.is_valid())
        return nullptr;
    return Read(this->GetOffset(aOffset), aSize);
}

size_t CStreamBuffer::Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const
{
    if (!aOffset.is_valid() || !aEnd.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(aOffset);
    size_t end_offset = this->GetOffset(aEnd);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, aBuffer, (end_offset - start_offset) + 1);
}

IStreamBuffer::Ptr CStreamBuffer::Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const
{
    if (!aOffset.is_valid() || !aEnd.is_valid())
        return nullptr;

    size_t start_offset = this->GetOffset(aOffset);
    size_t end_offset = this->GetOffset(aEnd);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, (end_offset - start_offset) + 1);
}

IStreamBuffer::Ptr CStreamBuffer::Read(const IStream::Iterator &aOffset) const
{
    IStreamBuffer::Ptr lStreamBuffer;
    if (aOffset.is_valid())
    {
        auto offset = this->GetOffset(aOffset);
        if (offset < m_Size)
            lStreamBuffer = Read(offset, m_Size - offset);
    }
    return lStreamBuffer;
}

const void* CStreamBuffer::GetData() const
{
    return m_Buff;
}

void* CStreamBuffer::GetData()
{
    return m_Buff;
}

//-------------------------------------------------------------------------------------
IStreamBuffer::Ptr CreateStreamBuffer(const void* aBuff, const size_t &aSize)
{
    return IStreamBuffer::Ptr(new CStreamBuffer(aBuff, aSize));
}

IStreamWriteBuffer::Ptr CreateStreamWriteBuffer(const void* aBuff, const size_t &aSize)
{
    return IStreamWriteBuffer::Ptr(new CStreamBuffer(aBuff, aSize));
}

IStreamWriteBuffer::Ptr CreateStreamWriteBuffer(const size_t &aSize)
{
    return IStreamWriteBuffer::Ptr(new CStreamBuffer(aSize));
}

}
}
