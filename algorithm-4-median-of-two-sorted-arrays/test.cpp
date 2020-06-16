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

TEST_F(LeetCode, test1)
{
  vector<int> v1{1, 3};
  vector<int> v2{2};
  auto answer = foo.findMedianSortedArrays(v1, v2);
  EXPECT_EQ(answer, 2.0);
}

TEST_F(LeetCode, test2)
{
  vector<int> v1{1, 2};
  vector<int> v2{3, 4};
  auto answer = foo.findMedianSortedArrays(v1, v2);
  EXPECT_EQ(answer, 2.5);
}

TEST_F(LeetCode, test3)
{
  vector<int> v1{1, 2};
  vector<int> v2{6, 8};
  auto answer = foo.findMedianSortedArrays(v1, v2);
  EXPECT_EQ(answer, 4);
}

TEST_F(LeetCode, singleElement)
{
  vector<int> v1{1};
  vector<int> v2;
  auto answer = foo.findMedianSortedArrays(v1, v2);
  EXPECT_EQ(answer, 1);
}

TEST_F(LeetCode, emptyV2)
{
  vector<int> v1{1, 2, 4, 8, 16, 32};
  vector<int> v2;
  auto answer = foo.findMedianSortedArrays(v1, v2);
  EXPECT_EQ(answer, 6);

  vector<int> v3{1, 2, 4, 8, 16, 32, 64};
  answer = foo.findMedianSortedArrays(v3, v2);
  EXPECT_EQ(answer, 8);
}

TEST_F(LeetCode, test6)
{
  vector<int> v1{1, 2, 4, 8, 16, 32};
  vector<int> v2{64, 128, 256, 512, 1024};
  auto answer = foo.findMedianSortedArrays(v1, v2);
  EXPECT_EQ(answer, 32);
}
