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
  EXPECT_EQ(foo.climbStairs(1), 1);
  EXPECT_EQ(foo.climbStairs(2), 2);
  EXPECT_EQ(foo.climbStairs(3), 3);
  EXPECT_EQ(foo.climbStairs(4), 5);
  EXPECT_EQ(foo.climbStairs(5), 8);
  EXPECT_EQ(foo.climbStairs(6), 13);
  EXPECT_EQ(foo.climbStairs(7), 21);
  EXPECT_EQ(foo.climbStairs(8), 34);
  EXPECT_EQ(foo.climbStairs(9), 55);
  EXPECT_EQ(foo.climbStairs(10), 89);
  EXPECT_EQ(foo.climbStairs(11), 144);
  EXPECT_EQ(foo.climbStairs(45), 1836311903);
}

