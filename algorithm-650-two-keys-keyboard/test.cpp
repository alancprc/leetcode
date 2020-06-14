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

TEST_F(LeetCode, test0)
{
  EXPECT_EQ(foo.minSteps(1), 0);
  EXPECT_EQ(foo.minSteps(0), 0);
}

TEST_F(LeetCode, test4)
{
  EXPECT_EQ(foo.minSteps(23), 23);
}

TEST_F(LeetCode, test2)
{
  EXPECT_EQ(foo.minSteps(997), 997);
}

TEST_F(LeetCode, test1)
{
  EXPECT_EQ(foo.minSteps(511), 80);
}

TEST_F(LeetCode, test3)
{
  EXPECT_EQ(foo.minSteps(1000), 21);
}

TEST_F(LeetCode, timeTest)
{
  const int loopNum = 1e6;
  for (int i = 0; i < loopNum; ++i) {
    foo.minSteps(1);
    foo.minSteps(23);
    foo.minSteps(511);
    foo.minSteps(1000);
  }
}
