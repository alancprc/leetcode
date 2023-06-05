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
  vector<int> nums = {2,3,6,7};
  int target = 7;
  vector<vector<int> > exp = {{2, 2, 3}, {7}};
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.func(nums, target), exp);
}

TEST_F(LeetCode, test2)
{
  vector<int> nums = {2, 3, 5};
  int target = 8;
  vector<vector<int> > exp = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.func(nums, target), exp);
}

TEST_F(LeetCode, test3)
{
  vector<int> nums = {2};
  int target = 1;
  vector<vector<int> > exp = {};
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.func(nums, target), exp);
}
