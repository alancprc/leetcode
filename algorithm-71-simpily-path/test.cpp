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
  string input = "/home/";
  string output = "/home";
  EXPECT_EQ(foo.simplifyPath(input), output);
}

TEST_F(LeetCode, test2)
{
  string input = "/../";
  string output = "/";
  EXPECT_EQ(foo.simplifyPath(input), output);
}

TEST_F(LeetCode, test3)
{
  string input = "/home//foo/";
  string output = "/home/foo";
  EXPECT_EQ(foo.simplifyPath(input), output);
}

TEST_F(LeetCode, test4)
{
  string input = "/a/./b/../../c/";
  string output = "/c";
  EXPECT_EQ(foo.simplifyPath(input), output);
}

TEST_F(LeetCode, test5)
{
  string input = "/a/../../b/../c//.//";
  string output = "/c";
  EXPECT_EQ(foo.simplifyPath(input), output);
}

TEST_F(LeetCode, test6)
{
  string input = "/a//b////c/d//././/..";
  string output = "/a/b/c";
  EXPECT_EQ(foo.simplifyPath(input), output);
}

TEST_F(LeetCode, test7)
{
  for (int i = 0; i < 1e6; ++i) {
    string input = "/a//b////c/d//././/..";
    string output = "/a/b/c";
  }
}
