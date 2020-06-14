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
  const int loopNum = 1e6;
};

TEST_F(LeetCode, test0)
{
  vector<int> input = {4, 9, 3};
  EXPECT_EQ(foo.findBestValue(input, 10), 3);
}

TEST_F(LeetCode, test1)
{
  vector<int> input = {2, 3, 5};
  EXPECT_EQ(foo.findBestValue(input, 10), 5);
}

TEST_F(LeetCode, test2)
{
  vector<int> input = {60864, 25176, 27249, 21296, 20204};
  EXPECT_EQ(foo.findBestValue(input, 56803), 11361);
}

TEST_F(LeetCode, timetest)
{
  vector<int> input = {60864, 25176, 27249, 21296, 20204};
  for (int i = 0; i < loopNum; ++i) foo.findBestValue(input, 56803);
}

TEST_F(LeetCode, testtimeV0)
{
  vector<int> input = {60864, 25176, 27249, 21296, 20204};
  for (int i = 0; i < loopNum; ++i) foo.findBestValueV0(input, 56803);
}

TEST_F(LeetCode, testtimeV1)
{
  vector<int> input = {60864, 25176, 27249, 21296, 20204};
  for (int i = 0; i < loopNum; ++i) foo.findBestValueV1(input, 56803);
}
