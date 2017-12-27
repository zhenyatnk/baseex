#include <baseex/core/IIteratorException.hpp>
#include <baseex/core/IStream.hpp>

#include <cstring>
#include <cstdlib>

namespace baseex {
namespace core {

//-------------------------------------------------------------------------------------
IStream::Iterator::Iterator(IStream::Ptr aStream)
    : m_Stream(aStream), m_Offset(-1), m_Size(aStream->Size())
{}

void IStream::Iterator::rewind()
{
    m_Offset = -1;
}

bool IStream::Iterator::is_valid() const
{
    return m_Offset < m_Size && m_Offset >= 0;
}

bool IStream::Iterator::next()
{
    m_Offset += sizeof(uint8_t);
    return is_valid();
}

uint8_t IStream::Iterator::current()
{
    CHECK_THROW_BOOL(m_Offset >= 0, exceptions::iterator_invalid_position_error, "");
    CHECK_THROW_BOOL(is_valid(), exceptions::iterator_out_of_range_error, "");

    uint8_t value;
    m_Stream->Read(m_Offset, (uint8_t*)(&value), sizeof(uint8_t));
    return value;
}

//-------------------------------------------------------------------------------------
ILinearStream::Iterator::Iterator(ILinearStream::Ptr aStream)
    : m_Stream(aStream), m_Offset(-1), m_Size(aStream->Size())
{}

void ILinearStream::Iterator::rewind()
{
    m_Offset = -1;
}

bool ILinearStream::Iterator::is_valid() const
{
    return m_Offset < m_Size && m_Offset >= 0;
}

bool ILinearStream::Iterator::next()
{
    m_Offset += sizeof(uint8_t);
    return is_valid();
}

uint8_t ILinearStream::Iterator::current()
{
    CHECK_THROW_BOOL(m_Offset >= 0, exceptions::iterator_invalid_position_error, "");
    CHECK_THROW_BOOL(is_valid(), exceptions::iterator_out_of_range_error, "");

    return m_Stream->GetElement<uint8_t>(m_Offset);;
}

}
}
