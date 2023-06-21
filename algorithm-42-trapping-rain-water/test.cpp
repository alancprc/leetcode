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
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  for (int i = loopNum; i--;) EXPECT_EQ(foo.trap(height), 6);
}
TEST_F(LeetCode, test2)
{
  vector<int> height = {4, 2, 0, 3, 2, 5};
  for (int i = loopNum; i--;) EXPECT_EQ(foo.trap(height), 9);
}
