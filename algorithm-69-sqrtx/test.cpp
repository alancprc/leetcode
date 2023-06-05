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
  const int loopNum = 1e7;
};

TEST_F(LeetCode, test1)
{
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.mySqrt(4), 2);
}

TEST_F(LeetCode, test2)
{
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.mySqrt(8), 2);
}

TEST_F(LeetCode, test3)
{
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.mySqrt(1), 1);
}

TEST_F(LeetCode, test4)
{
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.mySqrt(0), 0);
}

TEST_F(LeetCode, test5)
{
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.mySqrt(1073697800), 32767);
}

TEST_F(LeetCode, test6)
{
  for (int i = 0; i < loopNum; i++) EXPECT_EQ(foo.mySqrt(INT_MAX), 46340);
}
