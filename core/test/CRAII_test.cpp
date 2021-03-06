#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <baseex/core/RAII.hpp>
#include <future>

using namespace baseex::core;
//--------------------------------------------------------------------------------------------------------------------------------------
class ITestLocker
{
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class MockLocker
    :public ITestLocker
{
public:
    MOCK_METHOD0(lock, void());
    MOCK_METHOD0(unlock, void());
};
//--------------------------------------------------------------------------------------------------------------------------------------
class ITestExcLocker
{
public:
    virtual void force_lock() = 0;
    virtual void force_unlock() = 0;
};

class MockExcLocker
    :public ITestExcLocker
{
public:
    MOCK_METHOD0(force_lock, void());
    MOCK_METHOD0(force_unlock, void());
};

//--------------------------------------------------------------------------------------------------------------------------------------
class CRAII_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};
//--------------------------------------------------------------------------------------------------------------------------------------
TEST_F(CRAII_test, base_reference)
{
    using type = std::vector<std::string>;
    type lValue;
    {
        CRAII<type> lTest(lValue,
                          [](type& aValue) {aValue.push_back("ctor"); },
                          [](type& aValue) {aValue.push_back("dtor"); });
        ASSERT_EQ(1, lValue.size());
        ASSERT_STREQ("ctor", lValue[0].c_str());
    }
    ASSERT_EQ(2, lValue.size());
    ASSERT_STREQ("dtor", lValue[1].c_str());
}

TEST_F(CRAII_test, base_pointer_counter)
{
    using type = std::shared_ptr<int>;
    type lValue = std::make_shared<type::element_type>();
    {
        ASSERT_EQ(1, lValue.use_count());
        CRAII<type> lTest(lValue,
            [](type aValue) {},
            [](type aValue) {});

        ASSERT_EQ(2, lValue.use_count());
    }
    ASSERT_EQ(1, lValue.use_count());
}

TEST_F(CRAII_test, base_pointer)
{
    using type = std::shared_ptr<std::vector<std::string>>;
    type lValue = std::make_shared<type::element_type>();
    {
        CRAII<type> lTest(lValue,
            [](type aValue) {aValue->push_back("ctor"); },
            [](type aValue) {aValue->push_back("dtor"); });

        ASSERT_EQ(1, lValue->size());
        ASSERT_STREQ("ctor", (*lValue)[0].c_str());
    }
    ASSERT_EQ(2, lValue->size());
    ASSERT_STREQ("dtor", (*lValue)[1].c_str());
}

TEST_F(CRAII_test, base_void)
{
    using type = std::vector<std::string>;
    type lValue;
    {
        CRAII<void> lTest(
            [&lValue]() {lValue.push_back("ctor"); },
            [&lValue]() {lValue.push_back("dtor"); });
        ASSERT_EQ(1, lValue.size());
        ASSERT_STREQ("ctor", lValue[0].c_str());
    }
    ASSERT_EQ(2, lValue.size());
    ASSERT_STREQ("dtor", lValue[1].c_str());
}

TEST_F(CRAII_test, lock_guard_ex_reference)
{
    using type = MockLocker;
    type lValue;
    EXPECT_CALL(lValue, lock()).Times(1);
    EXPECT_CALL(lValue, unlock()).Times(1);
    {
        lock_guard_ex<type> lTest(lValue);
    }
}

TEST_F(CRAII_test, lock_guard_ex_pointer)
{
    using type = std::shared_ptr<MockLocker>;
    type lValue = std::make_shared<type::element_type>();
    EXPECT_CALL(*lValue, lock()).Times(1);
    EXPECT_CALL(*lValue, unlock()).Times(1);
    {
        lock_guard_ex<std::shared_ptr<ITestLocker>> lTest(lValue);
    }
}

TEST_F(CRAII_test, force_lock_guard_ex_reference)
{
    using type = MockExcLocker;
    type lValue;
    EXPECT_CALL(lValue, force_lock()).Times(1);
    EXPECT_CALL(lValue, force_unlock()).Times(1);
    {
        force_lock_guard_ex<type> lTest(lValue);
    }
}

TEST_F(CRAII_test, force_lock_guard_ex_pointer)
{
    using type = std::shared_ptr<MockExcLocker>;
    type lValue = std::make_shared<type::element_type>();
    EXPECT_CALL(*lValue, force_lock()).Times(1);
    EXPECT_CALL(*lValue, force_unlock()).Times(1);
    {
        force_lock_guard_ex<std::shared_ptr<ITestExcLocker>> lTest(lValue);
    }
}

TEST_F(CRAII_test, set_values_raii)
{
    using type = int;
    type lValue = 0;
    {
        set_values_raii<type> lTest(lValue, 10, 20);
        ASSERT_EQ(10, lValue);
    }
    ASSERT_EQ(20, lValue);
}

TEST_F(CRAII_test, set_values_raii_atomic)
{
    using type = std::atomic_int;
    type lValue(0);
    {
        set_values_raii<type> lTest(lValue, 10, 20);
        ASSERT_EQ(10, lValue);
    }
    ASSERT_EQ(20, lValue);
}

TEST_F(CRAII_test, thread_join_raii_empty)
{
    thread_join_raii lTest;
}

TEST_F(CRAII_test, thread_join_raii_pointer)
{
    using type = std::shared_ptr<std::thread>;
    bool lCompleted = false;
    type lValue = std::make_shared<type::element_type>([&lCompleted]() {lCompleted = true; });
    {
        thread_join_raii lTest(lValue);
    }
    ASSERT_EQ(true, lCompleted);
}

TEST_F(CRAII_test, thread_join_raii_pointer_notjoinable)
{
    using type = std::shared_ptr<std::thread>;
    type lValue = std::make_shared<type::element_type>();
    thread_join_raii lTest(lValue);
}

TEST_F(CRAII_test, thread_join_raii_lvalue)
{
    using type = std::thread;
    bool lCompleted = false;
    type lValue ([&lCompleted]() {lCompleted = true; });
    {
        thread_join_raii lTest(lValue);
    }
    ASSERT_EQ(true, lCompleted);
}

TEST_F(CRAII_test, thread_join_raii_lvalue_notjoinable)
{
    std::thread lValue;
    thread_join_raii lTest(lValue);
}

TEST_F(CRAII_test, thread_join_raii_rvalue)
{
    bool lCompleted = false;
    {
        thread_join_raii lTest(std::thread([&lCompleted]() {lCompleted = true; }));
    }
    ASSERT_EQ(true, lCompleted);
}

TEST_F(CRAII_test, thread_join_raii_rvalue_notjoinable)
{
    thread_join_raii lTest(std::thread([](){}));
}

TEST_F(CRAII_test, dtor_raii)
{
    int test = 0;
    {
        dtor_raii l([&test]() {test = 1; });
        ASSERT_EQ(0, test);
    }
    ASSERT_EQ(1, test);
}
