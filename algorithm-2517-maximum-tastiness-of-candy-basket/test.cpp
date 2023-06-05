#include <gmock/gmock.h>
#include <chrono>
#include <future>
#include <iostream>
#include "solution.h"

#include "print-time.cpp"

using namespace std;
using namespace ::testing;

typedef Solution Foo;

class LeetCode : public ::testing::Test
{
 public:
  void SetUp() {}

 protected:
  Foo foo;
  const int loopNum = 1e1;
};

TEST_F(LeetCode, test1)
{
  vector<int> nums = {13, 5, 1, 8, 21, 2};
  // k = 6, t = 1; 1, 2, 5, 8, 13, 21, | 1 3 3 5 8
  // k = 5, t = 3; 1,    5, 8, 13, 21, |   4 3 5 8
  // k = 4, t = 5; 1,       8, 13, 21, |     7 5 8
  // k = 3, t = 8; 1,          13, 21, |      12 8
  // k = 2, t = 8; 1,              21, |        20
  int k = 3;
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.maximumTastiness(nums, k), 8);
}

TEST_F(LeetCode, test2)
{
  vector<int> nums = {1,3,1};
  int k = 2;
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.maximumTastiness(nums, k), 2);
}

TEST_F(LeetCode, test3)
{
  vector<int> nums = {7, 7, 7, 7};
  int k = 2;
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.maximumTastiness(nums, k), 0);
}
