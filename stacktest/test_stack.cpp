#include "MyStack.h"

#include <gtest.h>

TEST(TStack, can_create)
{
	ASSERT_NO_THROW(TStack<int> s1(10));
}

TEST(TStack, can_get_size)
{
	TStack<int> s1(2);
	ASSERT_EQ(2, s1.GetSize());
}

TEST(TStack, can_get_top)
{
	TStack<int> s1(2);
	ASSERT_EQ(0, s1.GetTop());
}

TEST(TStack, can_push_element)
{
	TStack<int> s1(1);
	ASSERT_NO_THROW(s1.Push(10));
}

TEST(TStack, cant_push_element_when_stack_is_full)
{
	TStack<int> s1(1);
	s1.Push(10);
	ASSERT_ANY_THROW(s1.Push(10));
}

TEST(TStack, can_pop_element)
{
	TStack<int> s1(1);
	s1.Push(10);
	ASSERT_NO_THROW(s1.Get());
}

