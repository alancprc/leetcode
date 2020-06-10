#include <gmock/gmock.h>
#include <chrono>
#include <future>
#include <iostream>
#include "solution.h"

using namespace std;
using namespace ::testing;

typedef Solution Foo;

class LeetCode : public ::testing::Test
{
 public:
  void SetUp() {}

 protected:
  Foo foo;
};

TEST_F(LeetCode, test1)
{
  ListNode l11(3);
  ListNode l12(4, &l11);
  ListNode l1(2, &l12);

  ListNode l21(4);
  ListNode l22(6, &l21);
  ListNode l2(5, &l22);

  auto answer = foo.addTwoNumbers(&l1, &l2);
  EXPECT_THAT(answer->val, 7);
  ASSERT_NE(answer->next, nullptr);
  EXPECT_THAT(answer->next->val, 0);
  ASSERT_NE(answer->next->next, nullptr);
  EXPECT_THAT(answer->next->next->val, 8);
}

TEST_F(LeetCode, test2)
{
  ListNode l11(3);
  ListNode l12(4, &l11);
  ListNode l1(2, &l12);

  ListNode l21(4);
  ListNode l2(9, &l21);

  auto answer = foo.addTwoNumbers(&l1, &l2);
  EXPECT_THAT(answer->val, 1);
  ASSERT_NE(answer->next, nullptr);
  EXPECT_THAT(answer->next->val, 9);
  ASSERT_NE(answer->next->next, nullptr);
  EXPECT_THAT(answer->next->next->val, 3);
}

TEST_F(LeetCode, test3)
{
  ListNode l1(5);

  ListNode l2(5);

  auto answer = foo.addTwoNumbers(&l1, &l2);
  EXPECT_THAT(answer->val, 0);
  ASSERT_NE(answer->next, nullptr);
  EXPECT_THAT(answer->next->val, 1);
}
