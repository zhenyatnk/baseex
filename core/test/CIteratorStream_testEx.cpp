#include <gtest/gtest.h>
#include <baseex/core/IStream.hpp>
#include <future>

//--------------------------------------------------------------------------------------------------------------------------------------
using namespace baseex::core::experimental;

namespace
{
std::string ConvertToString(IStream::Ptr aStream)
{
    uint8_t *lBuffer = new uint8_t[aStream->Size()];
    aStream->Read(0, lBuffer, aStream->Size());
    std::string lRet((char*)lBuffer, aStream->Size());
    delete[] lBuffer;
    return lRet;
}
std::string ConvertToString(IStreamBuffer::Ptr aStream)
{
    return std::string((const char *)aStream->GetData(), aStream->Size());
}
}

class CIteratorStream_testEx
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

TEST_F(CIteratorStream_testEx, next_empty_source)
{
    std::string buffer = "";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(false, iterator.next());
}

TEST_F(CIteratorStream_testEx, next_non_empty_source)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.next());
}

TEST_F(CIteratorStream_testEx, next_size_elements_1)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.next())
        ++size_elements;

    ASSERT_EQ(1, size_elements);
}

TEST_F(CIteratorStream_testEx, next_size_elements_2)
{
    std::string buffer = "12345";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.next())
        ++size_elements;

    ASSERT_EQ(buffer.size(), size_elements);
}

TEST_F(CIteratorStream_testEx, next_rewind)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.next());
    ASSERT_EQ(false, iterator.next());
    iterator.rewind();
    ASSERT_EQ(true, iterator.next());
}

TEST_F(CIteratorStream_testEx, next_some_elements)
{
    std::string buffer = "test1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    std::string result = "";
    while (iterator.next())
        result += iterator.current();

    ASSERT_STREQ(buffer.c_str(), result.c_str());
}

TEST_F(CIteratorStream_testEx, throw_invalid_position)
{
    std::string buffer = "";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_THROW(iterator.current(), baseex::core::exceptions::iterator_invalid_position_error);
}

TEST_F(CIteratorStream_testEx, next_throw_out_of_range)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.next());
    ASSERT_EQ(false, iterator.next());

    ASSERT_THROW(iterator.current(), baseex::core::exceptions::iterator_out_of_range_error);
}

TEST_F(CIteratorStream_testEx, prev_empty_source)
{
    std::string buffer = "";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(false, iterator.prev());
}

TEST_F(CIteratorStream_testEx, prev_non_empty_source)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.prev());
}

TEST_F(CIteratorStream_testEx, prev_size_elements_1)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.prev())
        ++size_elements;

    ASSERT_EQ(1, size_elements);
}

TEST_F(CIteratorStream_testEx, prev_size_elements_2)
{
    std::string buffer = "12345";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.prev())
        ++size_elements;

    ASSERT_EQ(buffer.size(), size_elements);
}

TEST_F(CIteratorStream_testEx, prev_rewind)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.prev());
    ASSERT_EQ(false, iterator.prev());
    iterator.rewind();
    ASSERT_EQ(true, iterator.prev());
}

TEST_F(CIteratorStream_testEx, prev_some_elements)
{
    std::string buffer = "test1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    std::string result = "";
    while (iterator.prev())
        result += iterator.current();

    ASSERT_STREQ("1tset", result.c_str());
}

TEST_F(CIteratorStream_testEx, prev_throw_out_of_range)
{
    std::string buffer = "1";
    auto iterator = CreateStreamBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.prev());
    ASSERT_EQ(false, iterator.prev());

    ASSERT_THROW(iterator.current(), baseex::core::exceptions::iterator_out_of_range_error);
}

TEST_F(CIteratorStream_testEx, read_stream_toend_iterator_start)
{
    std::string buffer = "1";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();

    ASSERT_STREQ(buffer.c_str(), ConvertToString(stream->Read(iterator)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_toend_iterator_end)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    iterator.next();

    ASSERT_STREQ("3", ConvertToString(stream->Read(iterator)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_start_toend_iterator_1)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    auto start = iterator;
    iterator.next();
    auto end = iterator;

    ASSERT_STREQ("12", ConvertToString(stream->Read(start, end)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_start_toend_iterator_2)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    auto start = iterator;
    iterator.next();
    iterator.next();
    auto end = iterator;

    ASSERT_STREQ("123", ConvertToString(stream->Read(start, end)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_start_toend_iterator_3)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    auto start = iterator;
    iterator.next();
    auto end = iterator;

    ASSERT_STREQ("23", ConvertToString(stream->Read(start, end)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_start_start_iterator_1)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    auto start = iterator;
    iterator.next();
    iterator.next();

    ASSERT_STREQ("1", ConvertToString(stream->Read(start, start)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_start_start_iterator_2)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    auto start = iterator;
    iterator.next();

    ASSERT_STREQ("2", ConvertToString(stream->Read(start, start)).c_str());
}

TEST_F(CIteratorStream_testEx, read_stream_start_start_iterator_3)
{
    std::string buffer = "123";
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    iterator.next();
    auto start = iterator;

    ASSERT_STREQ("3", ConvertToString(stream->Read(start, start)).c_str());
}

//----


TEST_F(CIteratorStream_testEx, read_toend_iterator_start)
{
    std::string buffer = "1";
    auto lSecondPartSize = 1;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();

    stream->Read(iterator, lResult, lSecondPartSize);

    ASSERT_STREQ(buffer.c_str(), (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_toend_iterator_end)
{
    std::string buffer = "123";

    auto lSecondPartSize = 1;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    iterator.next();

    stream->Read(iterator, lResult, lSecondPartSize);

    ASSERT_STREQ("3", (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_start_toend_iterator_1)
{
    std::string buffer = "123";
    auto lSecondPartSize = 2;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    auto start = iterator;
    iterator.next();
    auto end = iterator;

    stream->Read(start, end, lResult);

    ASSERT_STREQ("12", (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_start_toend_iterator_2)
{
    std::string buffer = "123";
    auto lSecondPartSize = 3;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    auto start = iterator;
    iterator.next();
    iterator.next();
    auto end = iterator;

    stream->Read(start, end, lResult);

    ASSERT_STREQ("123", (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_start_toend_iterator_3)
{
    std::string buffer = "123";
    auto lSecondPartSize = 2;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;
    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    auto start = iterator;
    iterator.next();
    auto end = iterator;

    stream->Read(start, end, lResult);

    ASSERT_STREQ("23", (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_start_start_iterator_1)
{
    std::string buffer = "123";
    auto lSecondPartSize = 1;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    auto start = iterator;
    iterator.next();
    iterator.next();

    stream->Read(start, start, lResult);

    ASSERT_STREQ("1", (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_start_start_iterator_2)
{
    std::string buffer = "123";
    auto lSecondPartSize = 1;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    auto start = iterator;
    iterator.next();

    stream->Read(start, start, lResult);

    ASSERT_STREQ("2", (char*)lResult);
    delete[] lResult;
}

TEST_F(CIteratorStream_testEx, read_start_start_iterator_3)
{
    std::string buffer = "123";
    auto lSecondPartSize = 1;
    uint8_t *lResult = new uint8_t[lSecondPartSize + 1];
    lResult[lSecondPartSize] = 0;

    auto stream = CreateStreamBuffer(buffer.c_str(), buffer.size());
    auto iterator = stream->CreateIterator();
    iterator.next();
    iterator.next();
    iterator.next();
    auto start = iterator;

    stream->Read(start, start, lResult);

    ASSERT_STREQ("3", (char*)lResult);
    delete[] lResult;
}