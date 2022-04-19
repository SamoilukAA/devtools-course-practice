// Copyright 2022 Samoiluk Anastasiya

#include <gtest/gtest.h>
#include "include/samoiluk_a_stack.h"

TEST(Stack, can_create_stack_with_positive_length) {
    ASSERT_NO_THROW(Stack<int> s(5));
}

TEST(Stack, can_create_copied_stack) {
    Stack<int> s(10);

    ASSERT_NO_THROW(Stack<int> s1(s));
}

TEST(Stack, can_push_and_pop_element) {
    Stack<int> s(4);
    s.push(1);
    s.push(2);

    EXPECT_EQ(2, s.pop());
}

TEST(Stack, can_get_last) {
    Stack<int> s(4);
    s.push(1);
    s.push(2);

    EXPECT_EQ(2, s.getLast());
}

TEST(Stack, can_get_size) {
    Stack<int> s(10);

    EXPECT_EQ(10, s.getSize());
}

TEST(Stack, throws_when_add_element_to_full_stack) {
    Stack<int> s(2);
    s.push(1);
    s.push(2);

    ASSERT_ANY_THROW(s.push(3));
}

TEST(Stack, throws_when_pop_element_from_empty_stack) {
    Stack<int> s;

    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_assign_stack_to_itself) {
    Stack<int> s(5);

    ASSERT_NO_THROW(s = s);
}

TEST(Stack, can_assign_stacks_of_equal_size) {
    Stack<int> s(2);
    Stack<int> s1(2);
    s1.push(1);
    s1.push(2);

    ASSERT_NO_THROW(s = s1);
}

TEST(Stack, can_assign_stacks_of_different_size) {
    Stack<int> s(2);
    Stack<int> s1(3);
    s1.push(1);
    s1.push(2);

    ASSERT_NO_THROW(s = s1);
}
