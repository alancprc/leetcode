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
  const int loopNum = 1e0;
};

TEST_F(LeetCode, test1)
{
  vector<int> nums = {2, -1, 2};
  int k = 3;
  int exp = 1;
  for (int i = loopNum; i--;) EXPECT_EQ(foo.waysToPartition(nums, k), exp);
}
TEST_F(LeetCode, test2)
{
  vector<int> nums = {0,0,0};
  int k = 1;
  int exp = 2;
  for (int i = loopNum; i--;) EXPECT_EQ(foo.waysToPartition(nums, k), exp);
}
TEST_F(LeetCode, test3)
{
  vector<int> nums = {22, 4, -25, -20, -15, 15, -16, 7, 19, -10, 0, -13, -14};
  int k = -33;
  int exp = 4;
  for (int i = loopNum; i--;) EXPECT_EQ(foo.waysToPartition(nums, k), exp);
}
