#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <baseex/core/ITimerPassive.hpp>

#include <atomic>
#include <memory>
#include <thread>

using namespace baseex::core;
using namespace ::testing;
//--------------------------------------------------------------------------------------------------------------------------------------
class CTimerPassive_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

//--------------------------------------------------------------------------------------------------------------------------------------
TEST_F(CTimerPassive_test, only_create)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(1);
}

TEST_F(CTimerPassive_test, check_false)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(10000);
    ASSERT_EQ(false, lTimer->Check());
}

TEST_F(CTimerPassive_test, check_reset_false)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(10000);
    lTimer->Reset();
    ASSERT_EQ(false, lTimer->Check());
}

TEST_F(CTimerPassive_test, check)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(1);
    while (!lTimer->Check());
}

TEST_F(CTimerPassive_test, check_check)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(1);
    while (!lTimer->Check());
    ASSERT_EQ(true, lTimer->Check());
}

TEST_F(CTimerPassive_test, check_reset)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(1);
    while (!lTimer->Check());
    lTimer->Reset();
}

TEST_F(CTimerPassive_test, check_reset_check)
{
    ITimerPassive::Ptr lTimer = CreateTimerPassive(1);
    while (!lTimer->Check());
    lTimer->Reset();
    while (!lTimer->Check());
}
