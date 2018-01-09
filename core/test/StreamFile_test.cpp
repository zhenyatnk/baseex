#include <baseex/core/IStream.hpp>
#include <gtest/gtest.h>

using namespace baseex::core;

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

}

class StreamFile_test
    :public ::testing::Test
{
public:
	void SetUp()
	{}
};

//--------------------------------------------------------------------------------------------------------------------------------------
TEST_F(StreamFile_test, size)
{
    IStream::Ptr lStream = CreateStreamFile(baseex::core::CFileName(L"../test.txt"));
    ASSERT_EQ(11, lStream->Size());
}

TEST_F(StreamFile_test, read_buffer_full)
{
    IStream::Ptr lStream = CreateStreamFile(baseex::core::CFileName(L"../test.txt"));
    uint8_t *lResult = new uint8_t[lStream->Size() + 1];
    lStream->Read(0, lResult, lStream->Size());
    lResult[lStream->Size()] = 0;
    EXPECT_STREQ("test1 test2", (char*)lResult);
    delete[] lResult;
}

TEST_F(StreamFile_test, opt_size)
{
    IStream::Ptr lStream = CreateStreamFileOpt(baseex::core::CFileName(L"../test.txt"));
    ASSERT_EQ(11, lStream->Size());
}

TEST_F(StreamFile_test, opt_read_buffer_full)
{
    IStream::Ptr lStream = CreateStreamFileOpt(baseex::core::CFileName(L"../test.txt"));
    uint8_t *lResult = new uint8_t[lStream->Size() + 1];
    lStream->Read(0, lResult, lStream->Size());
    lResult[lStream->Size()] = 0;
    EXPECT_STREQ("test1 test2", (char*)lResult);
    delete[] lResult;
}
