#include <gtest/gtest.h>
#include <baseex/core/IStream.hpp>
#include <future>

//--------------------------------------------------------------------------------------------------------------------------------------
using namespace baseex::core;

class CIteratorStreamLinear_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

TEST_F(CIteratorStreamLinear_test, next_empty_source)
{
    std::string buffer = "";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(false, iterator.next());
}

TEST_F(CIteratorStreamLinear_test, next_non_empty_source)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.next());
}

TEST_F(CIteratorStreamLinear_test, next_size_elements_1)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.next())
        ++size_elements;

    ASSERT_EQ(1, size_elements);
}

TEST_F(CIteratorStreamLinear_test, next_size_elements_2)
{
    std::string buffer = "12345";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.next())
        ++size_elements;

    ASSERT_EQ(buffer.size(), size_elements);
}

TEST_F(CIteratorStreamLinear_test, rewind)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.next());
    ASSERT_EQ(false, iterator.next());
    iterator.rewind();
    ASSERT_EQ(true, iterator.next());
}

TEST_F(CIteratorStreamLinear_test, next_some_elements)
{
    std::string buffer = "test1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    std::string result = "";
    while (iterator.next())
        result += iterator.current();

    ASSERT_STREQ(buffer.c_str(), result.c_str());
}

TEST_F(CIteratorStreamLinear_test, throw_invalid_position)
{
    std::string buffer = "";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_THROW(iterator.current(), exceptions::iterator_invalid_position_error);
}

TEST_F(CIteratorStreamLinear_test, next_throw_out_of_range)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.next());
    ASSERT_EQ(false, iterator.next());

    ASSERT_THROW(iterator.current(), exceptions::iterator_out_of_range_error);
}


TEST_F(CIteratorStreamLinear_test, prev_empty_source)
{
    std::string buffer = "";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(false, iterator.prev());
}

TEST_F(CIteratorStreamLinear_test, prev_non_empty_source)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.prev());
}

TEST_F(CIteratorStreamLinear_test, prev_size_elements_1)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.prev())
        ++size_elements;

    ASSERT_EQ(1, size_elements);
}

TEST_F(CIteratorStreamLinear_test, prev_size_elements_2)
{
    std::string buffer = "12345";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();

    int size_elements = 0;
    while (iterator.prev())
        ++size_elements;

    ASSERT_EQ(buffer.size(), size_elements);
}

TEST_F(CIteratorStreamLinear_test, prev_rewind)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.prev());
    ASSERT_EQ(false, iterator.prev());
    iterator.rewind();
    ASSERT_EQ(true, iterator.prev());
}

TEST_F(CIteratorStreamLinear_test, prev_some_elements)
{
    std::string buffer = "test1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    std::string result = "";
    while (iterator.prev())
        result += iterator.current();

    ASSERT_STREQ("1tset", result.c_str());
}

TEST_F(CIteratorStreamLinear_test, prev_throw_out_of_range)
{
    std::string buffer = "1";
    auto iterator = baseex::core::CreateLinearBuffer(buffer.c_str(), buffer.size())->CreateIterator();
    ASSERT_EQ(true, iterator.prev());
    ASSERT_EQ(false, iterator.prev());

    ASSERT_THROW(iterator.current(), exceptions::iterator_out_of_range_error);
}