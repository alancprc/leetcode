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

TEST_F(LeetCode, printTest)
{
    TreeNode root(1);
    TreeNode n401(401);
    TreeNode n349(349);
    TreeNode n88(88);
    TreeNode n90(90);
    root.left = &n401;
    n401.left = &n349;
    n401.right = &n88;
    n349.left = &n90;

    EXPECT_THAT(print(&root), ElementsAre(1, 401, 349, 88, 90));
}

TEST_F(LeetCode, test0)
{
  string input = "1-2--3--4-5--6--7";
  auto tree = foo.recoverFromPreorder(input);
  EXPECT_THAT(print(tree), ElementsAre(1, 2, 5, 3, 4, 6, 7));
}

TEST_F(LeetCode, test1)
{
  string input = "1-2--3---4-5--6---7";
  auto tree = foo.recoverFromPreorder(input);
  EXPECT_THAT(print(tree), ElementsAre(1,2,5,3,0,6,0,4,0,7));
}

TEST_F(LeetCode, test2)
{
  string input = "1-401--349---90--88";
  auto tree = foo.recoverFromPreorder(input);
  EXPECT_THAT(print(tree), ElementsAre(1,401,0,349,88,90));
}

