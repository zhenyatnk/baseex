#include <baseex/core/IIteratorException.hpp>
#include <baseex/core/IStream.hpp>

#include <cstring>
#include <cstdlib>

namespace baseex {
namespace core {

//-------------------------------------------------------------------------------------
IStream::Iterator::Iterator(IStream::Ptr aStream)
    : m_Stream(aStream), m_Offset(-1), m_Size(aStream->Size()), m_IsRewind(true)
{}

void IStream::Iterator::rewind()
{
    m_IsRewind = true;
}

bool IStream::Iterator::is_valid() const
{
    return m_Offset < m_Size && m_Offset >= 0 && !m_IsRewind;
}

bool IStream::Iterator::next()
{
    if (m_IsRewind)
    {
        m_Offset = 0;
        m_IsRewind = false;
    }
    else
        m_Offset += sizeof(uint8_t);
    return is_valid();
}

bool IStream::Iterator::prev()
{
    if (m_IsRewind)
    {
        m_Offset = m_Size - 1;
        m_IsRewind = false;
    }
    else
        m_Offset -= sizeof(uint8_t);
    return is_valid();
}

uint8_t IStream::Iterator::current()
{
    CHECK_THROW_BOOL(!m_IsRewind, exceptions::iterator_invalid_position_error, "");
    CHECK_THROW_BOOL(is_valid(), exceptions::iterator_out_of_range_error, "");

    uint8_t value;
    m_Stream->Read(m_Offset, (uint8_t*)(&value), sizeof(uint8_t));
    return value;
}

//-------------------------------------------------------------------------------------
ILinearStream::Iterator::Iterator(ILinearStream::Ptr aStream)
    : m_Stream(aStream), m_Offset(-1), m_Size(aStream->Size()), m_IsRewind(true)
{}

void ILinearStream::Iterator::rewind()
{
    m_IsRewind = true;
}

bool ILinearStream::Iterator::is_valid() const
{
    return m_Offset < m_Size && m_Offset >= 0 && !m_IsRewind;
}

bool ILinearStream::Iterator::next()
{
    if (m_IsRewind)
    {
        m_Offset = 0;
        m_IsRewind = false;
    }
    else
        m_Offset += sizeof(uint8_t);
    return is_valid();
}

bool ILinearStream::Iterator::prev()
{
    if (m_IsRewind)
    {
        m_Offset = m_Size - 1;
        m_IsRewind = false;
    }
    else
        m_Offset -= sizeof(uint8_t);
    return is_valid();
}
uint8_t ILinearStream::Iterator::current()
{
    CHECK_THROW_BOOL(!m_IsRewind, exceptions::iterator_invalid_position_error, "");
    CHECK_THROW_BOOL(is_valid(), exceptions::iterator_out_of_range_error, "");

    return m_Stream->GetElement<uint8_t>(m_Offset);
}

namespace experimental {
IStream::Iterator::Iterator(IStream::Ptr aStream)
    : m_Stream(aStream), m_Offset(-1), m_Size(aStream->Size()), m_IsRewind(true)
{}

void IStream::Iterator::rewind()
{
    m_IsRewind = true;
}

bool IStream::Iterator::is_valid() const
{
    return m_Offset < m_Size && m_Offset >= 0 && !m_IsRewind;
}

bool IStream::Iterator::next()
{
    if (m_IsRewind)
    {
        m_Offset = 0;
        m_IsRewind = false;
    }
    else
        m_Offset += sizeof(uint8_t);
    return is_valid();
}

bool IStream::Iterator::prev()
{
    if (m_IsRewind)
    {
        m_Offset = m_Size - 1;
        m_IsRewind = false;
    }
    else
        m_Offset -= sizeof(uint8_t);
    return is_valid();
}

uint8_t IStream::Iterator::current()
{
    CHECK_THROW_BOOL(!m_IsRewind, exceptions::iterator_invalid_position_error, "");
    CHECK_THROW_BOOL(is_valid(), exceptions::iterator_out_of_range_error, "");

    uint8_t value;
    m_Stream->Read(m_Offset, (uint8_t*)(&value), sizeof(uint8_t));
    return value;
}
}

}
}
