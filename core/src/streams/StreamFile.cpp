#include <baseex/core/IStream.hpp>
#include <baseex/core/CFileName.hpp>
#include <baseex/core/RAII.hpp>
#include <baseex/core/Unicode.hpp>

#include <cstring>
#include <cstdlib>
#include <fstream>

namespace baseex {
namespace core {

class CStreamFile
    :public IStream
{

public:
    explicit CStreamFile(const CFileName &aFilename);
    ~CStreamFile();

    //IStream
    virtual size_t Size() const override;

    virtual size_t             Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const override;
    virtual IStreamBuffer::Ptr Read(size_t aOffset, size_t aSize) const override;
    virtual size_t             Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset, size_t aSize) const override;
    virtual size_t             Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset) const override;

protected:
    std::shared_ptr<std::fstream> GetFile() const;

private:
    mutable std::shared_ptr<std::fstream> m_File;
    CFileName m_Filename;
    mutable size_t m_Size;
};

CStreamFile::CStreamFile(const CFileName &aFilename)
    :m_Filename(aFilename), m_Size(std::string::npos)
{}

CStreamFile::~CStreamFile()
{
    if (!!m_File)
        m_File->close();
}

size_t CStreamFile::Size() const
{
    if (std::string::npos == m_Size)
    {
        RAII<std::streampos> l([file = GetFile()](std::streampos &pos) {pos = file->tellg(); },
                               [file = GetFile()](std::streampos &pos) {file->seekg(pos, file->beg);});

        GetFile()->seekg(0, GetFile()->end);
        m_Size = GetFile()->tellg();
    }
    return m_Size;
}

size_t CStreamFile::Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const
{
    if (aOffset < Size())
    {
        GetFile()->seekg(aOffset, GetFile()->beg);
        GetFile()->read((char*)aBuffer, aSize);
        return aSize;
    }
    else
        return 0;
}

IStreamBuffer::Ptr CStreamFile::Read(size_t aOffset, size_t aSize) const
{
    IStreamWriteBuffer::Ptr buffer = CreateStreamWriteBuffer(aSize);
    Read(aOffset, (uint8_t*)buffer->GetData(), aSize);
    return buffer;
}

size_t CStreamFile::Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const
{
    if (!aOffset.is_valid())
        return 0;
    return Read(this->GetOffset(aOffset), aBuffer, aSize);
}

IStreamBuffer::Ptr CStreamFile::Read(const IStream::Iterator &aOffset, size_t aSize) const
{
    if (!aOffset.is_valid())
        return nullptr;
    return Read(this->GetOffset(aOffset), aSize);
}

size_t CStreamFile::Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const
{
    if (!aOffset.is_valid() || !aEnd.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(aOffset);
    size_t end_offset = this->GetOffset(aEnd);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, aBuffer, (end_offset - start_offset) + 1);
}

IStreamBuffer::Ptr CStreamFile::Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const
{
    if (!aOffset.is_valid() || !aEnd.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(aOffset);
    size_t end_offset = this->GetOffset(aEnd);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, (end_offset - start_offset) + 1);
}

IStreamBuffer::Ptr CStreamFile::Read(const IStream::Iterator &aOffset) const
{
    IStreamBuffer::Ptr lStreamBuffer;
    if (aOffset.is_valid())
    {
        auto offset = this->GetOffset(aOffset);
        if (offset < Size())
            lStreamBuffer = Read(offset, Size() - offset);
    }
    return lStreamBuffer;
}

std::shared_ptr<std::fstream> CStreamFile::GetFile() const
{
    if (!m_File)
    {
        m_File = std::make_shared<std::fstream>();
        //TODO if macos using converting wchart to char
        m_File->open(m_Filename.GetFullFileName().c_str(), std::fstream::in);
        CHECK_THROW_BOOL(m_File->is_open(), exceptions::file_stream_error, "Can't open file = '" + convert(m_Filename.GetFullFileName()) +"'");
    }
    return m_File;
}

//-------------------------------------------------------------------------------------
IStream::Ptr CreateStreamFile(const CFileName &aFilename)
{
    return IStream::Ptr(new CStreamFile(aFilename));
}


class CStreamFileOpt
    :public IStream
{

public:
    explicit CStreamFileOpt(const CFileName &aFilename);
    ~CStreamFileOpt();

    //IStream
    virtual size_t Size() const override;

    virtual size_t             Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const override;
    virtual IStreamBuffer::Ptr Read(size_t aOffset, size_t aSize) const override;
    virtual size_t             Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset, size_t aSize) const override;
    virtual size_t             Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const override;
    virtual IStreamBuffer::Ptr Read(const IStream::Iterator &aOffset) const override;

private:
    mutable std::fstream m_File;
    CFileName m_Filename;
    mutable size_t m_Size;
};

CStreamFileOpt::CStreamFileOpt(const CFileName &aFilename)
    :m_Filename(aFilename), m_Size(std::string::npos)
{
    //TODO if macos using converting wchart to char
    m_File.open(m_Filename.GetFullFileName().c_str(), std::fstream::in);
    CHECK_THROW_BOOL(m_File.is_open(), exceptions::file_stream_error, "Can't open file = '" + convert(m_Filename.GetFullFileName()) + "'");

    m_File.seekg(0, m_File.end);
    m_Size = m_File.tellg();
    m_File.seekg(0, m_File.beg);
}

CStreamFileOpt::~CStreamFileOpt()
{
    m_File.close();
}

size_t CStreamFileOpt::Size() const
{
    return m_Size;
}

size_t CStreamFileOpt::Read(size_t aOffset, uint8_t* aBuffer, size_t aSize) const
{
    if (aOffset < m_Size)
    {
        m_File.seekg(aOffset, m_File.beg);
        m_File.read((char*)aBuffer, aSize);
        return aSize;
    }
    else
        return 0;
}

IStreamBuffer::Ptr CStreamFileOpt::Read(size_t aOffset, size_t aSize) const
{
    IStreamWriteBuffer::Ptr buffer = CreateStreamWriteBuffer(aSize);
    Read(aOffset, (uint8_t*)buffer->GetData(), aSize);
    return buffer;
}

size_t CStreamFileOpt::Read(const IStream::Iterator &aOffset, uint8_t* aBuffer, size_t aSize) const
{
    if (!aOffset.is_valid())
        return 0;
    return Read(this->GetOffset(aOffset), aBuffer, aSize);
}

IStreamBuffer::Ptr CStreamFileOpt::Read(const IStream::Iterator &aOffset, size_t aSize) const
{
    if (!aOffset.is_valid())
        return nullptr;
    return Read(this->GetOffset(aOffset), aSize);
}

size_t CStreamFileOpt::Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd, uint8_t* aBuffer) const
{
    if (!aOffset.is_valid() || !aEnd.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(aOffset);
    size_t end_offset = this->GetOffset(aEnd);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, aBuffer, (end_offset - start_offset) + 1);
}

IStreamBuffer::Ptr CStreamFileOpt::Read(const IStream::Iterator &aOffset, const IStream::Iterator &aEnd) const
{
    if (!aOffset.is_valid() || !aEnd.is_valid())
        return 0;

    size_t start_offset = this->GetOffset(aOffset);
    size_t end_offset = this->GetOffset(aEnd);

    if (start_offset > end_offset)
        std::swap(start_offset, end_offset);

    return Read(start_offset, (end_offset - start_offset) + 1);
}

IStreamBuffer::Ptr CStreamFileOpt::Read(const IStream::Iterator &aOffset) const
{
    IStreamBuffer::Ptr lStreamBuffer;
    if (aOffset.is_valid())
    {
        auto offset = this->GetOffset(aOffset);
        if (offset < Size())
            lStreamBuffer = Read(offset, Size() - offset);
    }
    return lStreamBuffer;
}

IStream::Ptr CreateStreamFileOpt(const CFileName &aFilename)
{
    return IStream::Ptr(new CStreamFileOpt(aFilename));
}

}
}
