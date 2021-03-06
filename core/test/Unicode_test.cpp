#include <baseex/core/Unicode.hpp>

#include <gtest/gtest.h>

//--------------------------------------------------
using namespace baseex::core;

class Unicode
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

TEST_F(Unicode, ws2s)
{
    std::wstring lTest = L"test";
    ASSERT_STREQ("test", convert(lTest).c_str());
}

TEST_F(Unicode, s2ws)
{
    std::string lTest = "test";
    ASSERT_STREQ(L"test", convert(lTest).c_str());
}

TEST_F(Unicode, s2ws2s)
{
    std::string lTest = "test";
    ASSERT_STREQ(lTest.c_str(), convert(convert(lTest)).c_str());
}

TEST_F(Unicode, ws2s2ws)
{
    std::wstring lTest = L"test";
    ASSERT_STREQ(lTest.c_str(), convert(convert(lTest)).c_str());
}

TEST_F(Unicode, ru2s)
{
//    TODO russian test for converter
    std::wstring lTest = L"rs";
    ASSERT_STREQ("rs", convert(lTest).c_str());
}
