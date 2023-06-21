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
  string s = "abcda";
  vector<vector<int> > queries = {
      {3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
  vector<bool> exp = {true, false, false, true, true};
  for (int i = loopNum; i--;)
    EXPECT_EQ(foo.canMakePaliQueries(s, queries), exp);
}
