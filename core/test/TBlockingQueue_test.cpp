#include <gtest/gtest.h>
#include <baseex/core/TBlockingQueue.hpp>

#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------------
using namespace baseex::core;

class TBlockingQueue_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}

};
//--------------------------------------------------------------------------------------------------------------------------------------
TEST_F(TBlockingQueue_test, Push_Container)
{
    TBlockingQueue<int> queue;
    std::vector<int> container {1,2,3};
    
    queue.Push(container);
}

TEST_F(TBlockingQueue_test, Push_NonContainer)
{
    TBlockingQueue<int> queue;
    queue.Push(1);
}

TEST_F(TBlockingQueue_test, Push_Queue)
{
    TBlockingQueue<int> queue;
    std::queue<int> container;
    container.push(1);
    container.push(2);
    container.push(3);
    queue.Push(container);
}

TEST_F(TBlockingQueue_test, Push_Mixed)
{
    TBlockingQueue<int> queue;
    std::queue<int> container1;
    std::vector<int> container2 {1,2,3};
    
    container1.push(1);    container1.push(2);    container1.push(3);
    queue.Push(container1);
    queue.Push(container2);
}

TEST_F(TBlockingQueue_test, Get_first)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};

    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    ASSERT_EQ(1, queue.Get());
}

TEST_F(TBlockingQueue_test, Get_All)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};
    
    std::vector<int> nominal(firstContainer);
    nominal.insert(nominal.end(), secondContainer.begin(), secondContainer.end());
    
    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    for(const auto& element: nominal)
        ASSERT_EQ(element, queue.Get());
}

TEST_F(TBlockingQueue_test, GetContainer)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};
    
    std::vector<int> nominal(firstContainer);
    nominal.insert(nominal.end(), secondContainer.begin(), secondContainer.end());
    
    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    auto result = queue.GetContainer();
    
    ASSERT_EQ(nominal.size(), result.size());
    for(auto i = 0; i< nominal.size(); ++i)
        ASSERT_EQ(result[i], nominal[i]);
}

TEST_F(TBlockingQueue_test, GetContainer_Count)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};
    
    std::vector<int> nominal(firstContainer);
    nominal.insert(nominal.end(), secondContainer.begin(), secondContainer.end());
    
    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    auto result = queue.GetContainer(4);
    
    ASSERT_GE(4, result.size());
    for(auto i = 0; i< result.size(); ++i)
        ASSERT_EQ(result[i], nominal[i]);
}


TEST_F(TBlockingQueue_test, Get_All_NoExcept)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};
    
    std::vector<int> nominal(firstContainer);
    nominal.insert(nominal.end(), secondContainer.begin(), secondContainer.end());
    
    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    for(const auto& element: nominal)
    {
        int result;
        ASSERT_EQ(true, queue.Get(result));
        ASSERT_EQ(element, result);
    }
}

TEST_F(TBlockingQueue_test, GetContainer_NoExcept)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};
    
    std::vector<int> nominal(firstContainer);
    nominal.insert(nominal.end(), secondContainer.begin(), secondContainer.end());
    
    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    std::vector<int> result;
    ASSERT_EQ(true, queue.GetContainer(result));
    
    ASSERT_EQ(nominal.size(), result.size());
    for(auto i = 0; i< nominal.size(); ++i)
    {
        ASSERT_EQ(result[i], nominal[i]);
    }
}

TEST_F(TBlockingQueue_test, GetContainer_Count_NoExcept)
{
    TBlockingQueue<int> queue;
    std::vector<int> firstContainer {1,2,3};
    std::vector<int> secondContainer {4,5,6};
    
    std::vector<int> nominal(firstContainer);
    nominal.insert(nominal.end(), secondContainer.begin(), secondContainer.end());
    
    queue.Push(firstContainer);
    queue.Push(secondContainer);
    
    std::vector<int> result;
    ASSERT_EQ(true, queue.GetContainer(4, result));
    
    ASSERT_GE(4, result.size());
    for(auto i = 0; i< result.size(); ++i)
        ASSERT_EQ(result[i], nominal[i]);
}

TEST_F(TBlockingQueue_test, Close_Get)
{
    TBlockingQueue<int> queue;
    
    queue.Close();
    ASSERT_THROW(queue.Get(), exceptions::blockingqueue_closed_error);
}

TEST_F(TBlockingQueue_test, Close_GetContainer)
{
    TBlockingQueue<int> queue;
    
    queue.Close();
    ASSERT_THROW(queue.GetContainer(), exceptions::blockingqueue_closed_error);
}

TEST_F(TBlockingQueue_test, Close_GetContainer_Count)
{
    TBlockingQueue<int> queue;
    
    queue.Close();
    ASSERT_THROW(queue.GetContainer(4), exceptions::blockingqueue_closed_error);
}


TEST_F(TBlockingQueue_test, Close_Get_All_NoExcept)
{
    TBlockingQueue<int> queue;

    int result;
    queue.Close();
    ASSERT_EQ(false, queue.Get(result));
}

TEST_F(TBlockingQueue_test, Close_GetContainer_NoExcept)
{
    TBlockingQueue<int> queue;

    std::vector<int> result;
    queue.Close();
    ASSERT_EQ(false, queue.GetContainer(result));
}

TEST_F(TBlockingQueue_test, Close_GetContainer_Count_NoExcept)
{
    TBlockingQueue<int> queue;
    
    std::vector<int> result;
    queue.Close();
    ASSERT_EQ(false, queue.GetContainer(4, result));
}
