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
  int loopCount = 1e4;
  string longStr =
      "aginubkpmiardjlmasduzjfqnukdpiwsqehmisbwceqgnbunvxjwipowlybdhxvxdcknwlkzrchefbrazdyjsmhf"
      "aginubkpmiardjlmasduzjfqnukdpiwsqehmisbwceqgnbunvxjwipowlybdhxvxdcknwl"
      "kzrchefbrazdyjsmhf"
      "aginubkpmiardjlmasduzjfqnukdpiwsqehmisbwceqgnbunvxjwipowlybdhxvxdcknwl"
      "kzrchefbrazdyjsmhf"
      "aginubkpmiardjlmasduzjfqnukdpiwsqehmisbwceqgnbunvxjwipowlybdhxvxdcknwl"
      "kzrchefbrazdyjsmhf";
  int longStrAnswer = 16;
};

TEST_F(LeetCode, test1)
{
  string str = "abcabcbb";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 3);
}

TEST_F(LeetCode, test2)
{
  string str = "bbbbb";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 1);
}

TEST_F(LeetCode, test3)
{
  string str = "pwwkew";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 3);
}

TEST_F(LeetCode, emptyStrTest)
{
  string str = "";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 0);
}

TEST_F(LeetCode, singCharTest)
{
  string str = " ";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 1);
}

TEST_F(LeetCode, noRepeatTest)
{
  string str = "abc";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 3);
}

TEST_F(LeetCode, repeatAtBegins)
{
  string str = "aab";
  auto answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 2);

  str = "aaab";
  answer = foo.lengthOfLongestSubstring(str);
  EXPECT_EQ(answer, 2);
}

TEST_F(LeetCode, longStr)
{
  for (int i = 0; i < loopCount; ++i) {
    auto answer = foo.lengthOfLongestSubstring(longStr);
    EXPECT_EQ(answer, longStrAnswer);
  }
}

TEST_F(LeetCode, longStrHashMap)
{
  for (int i = 0; i < loopCount; ++i) {
    auto answer = foo.lengthOfLongestSubstringHashMap(longStr);
    EXPECT_EQ(answer, longStrAnswer);
  }
}
