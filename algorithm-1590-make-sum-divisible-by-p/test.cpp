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
  vector<int> nums = {3, 1, 4, 2};
  // index            0, 1, 2, 3 // 
  // left to right:   3, 4, 2, 4
  // right to left:   4, 1, 0, 2
  // sum=4
  // (sum4 - rmd2 + p6) % p6 == 2
  // p6 - 2 => 4
  // p6 - ( (sum4 - rmd2 + p6) % p6 )
  // right to left:4, 1, 0, 2
  //  right[y] = 4 - left[y - 1]
  //  left[x] = 4 - right[x + 1]
  //  left[x] - right[y] = p    => result = y - x - 1
  //  left[x] - (4-left[y-1]) = left[x] - 4 + left[y-1]  = p
  //  left[x] = p + 4 - left[y-1]
  int k = 6;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 1);
}

TEST_F(LeetCode, test1_1)
{
  vector<int> nums = {3, 1, 2, 5};
  //        index -1, 0, 1, 2, 3, 4  // pad 0 in both ends
  // left to right 0, 3, 4, 0, 5
  // right to left    5, 2, 1, 5, 0
  int k = 6;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 1);
    EXPECT_EQ(foo.minSubarrayUnorderedMultiMap(nums, k), 1);
    EXPECT_EQ(foo.minSubarrayTimeOut(nums, k), 1);
}

TEST_F(LeetCode, test2)
{
  vector<int> nums = {6, 3, 5, 2};
  //        index -1, 0, 1, 2, 3, 4  // pad 0 in both ends
  // left to right 0, 3, 4, 0, 5
  // right to left    5, 2, 1, 5, 0
  //
  // from left to right // 6, 0, 5, 7
  // right to left
  // 7, 1, 7, 2
  int k = 9;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 2);
    EXPECT_EQ(foo.minSubarrayTimeOut(nums, k), 2);
}

TEST_F(LeetCode, test2_2)
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 18};
  // 1, 3, 6, 0,   5,  1,  8,  6,  5,  5,  6,  8,  1,   5,   3
  // 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 123
  int k = 10;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 1);
  EXPECT_EQ(foo.minSubarray(nums, k), foo.minSubarrayTimeOut(nums, k));
  EXPECT_EQ(foo.minSubarrayTimeOut(nums, k), 1);
}


TEST_F(LeetCode, test3)
{
  vector<int> nums = {1, 2, 3};
  int k = 3;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 0);
}

TEST_F(LeetCode, test4)
{
  vector<int> nums = {1,2,3};
  int k = 7;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), -1);
}

TEST_F(LeetCode, test5)
{
  vector<int> nums = {1000000000, 1000000000, 1000000000};
  int k = 3;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 0);
}

TEST_F(LeetCode, test6)
{
  vector<int> nums = {3};
  int k = 5;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), -1);
}

TEST_F(LeetCode, test7)
{
  vector<int> nums = {1, 3};
  int k = 5;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), -1);
}

TEST_F(LeetCode, test9)
{
  vector<int> nums = {3, 6, 8, 1};
  int k = 8;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), -1);
}

TEST_F(LeetCode, test139)
{
  vector<int> nums(1e6, 1e9);
  int k = 1e9 - 1;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), -1);
}

// TEST_F(LeetCode, test139UnorderedMap)
// {
//   vector<int> nums(1e6, 1e9);
//   int k = 1e9 - 1;
//   for (int i = 0; i < loopNum; i++)
//     EXPECT_EQ(foo.minSubarrayUnorderedMap(nums, k), -1);
// }

TEST_F(LeetCode, test139UnordededMultiMap)
{
  vector<int> nums(1e6, 1e9);
  int k = 1e9 - 1;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarrayUnorderedMultiMap(nums, k), -1);
}
TEST_F(LeetCode, test89)
{
  vector<int> nums = {26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3};
  //                   0, 19, 
  int k = 26;
  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.minSubarray(nums, k), 3);
}

