#include "solution.h"
#include <gmock/gmock.h>
#include <future>
#include <iostream>
#include <chrono>

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
  vector<int> input = {2, 7, 11, 15};
  auto answer = foo.twoSum(input, 9);
  EXPECT_THAT(answer, ElementsAre(0, 1));
}

TEST_F(LeetCode, test2)
{
  vector<int> input = {15, 11, 7, 2};
  auto answer = foo.twoSum(input, 9);
  EXPECT_THAT(answer, ElementsAre(2, 3));
}
