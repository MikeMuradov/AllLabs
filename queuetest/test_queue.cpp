#include "MyQueue.h"

#include <gtest.h>

TEST(TQueue, can_create)
{
	ASSERT_NO_THROW(TQueue<int> s1(10));
}

TEST(TQueue, can_get_size)
{
	TQueue<int> s1(2);
	ASSERT_EQ(2, s1.GetSize());
}

TEST(TQueue, can_get_start)
{
	TQueue<int> s1(2);
	ASSERT_EQ(0, s1.GetStart());
}

TEST(TQueue, can_get_end)
{
	TQueue<int> s1(2);
	ASSERT_EQ(2, s1.GetEnd());
}

TEST(TQueue, can_get_count)
{
	TQueue<int> s1(2);
	ASSERT_EQ(0, s1.GetCount());
}

TEST(TQueue, can_push_element)
{
	TQueue<int> s1(1);
	ASSERT_NO_THROW(s1.Push(10));
}

