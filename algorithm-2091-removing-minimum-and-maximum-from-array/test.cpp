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
  vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
  for (int i = loopNum; i--;) EXPECT_EQ(foo.minimumDeletions(nums), 5);
}
TEST_F(LeetCode, test2)
{
  vector<int> nums = {0, -4, 19, 1, 8, -2, -3, 5};
  for (int i = loopNum; i--;) EXPECT_EQ(foo.minimumDeletions(nums), 3);
}
TEST_F(LeetCode, test3)
{
  vector<int> nums = {101};
  for (int i = loopNum; i--;) EXPECT_EQ(foo.minimumDeletions(nums), 1);
}
