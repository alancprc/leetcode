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
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n6(6);
  TreeNode n7(7);
  TreeNode n2(2, &n4, &n5);
  TreeNode n3(3, &n6, &n7);
  TreeNode n1(1, &n2, &n3);
  TreeNode* root = &n1;

  vector<int> to_delete { 3, 5 };

  TreeNode e4(4);
  TreeNode e6(6);
  TreeNode e7(7);
  TreeNode e2(2, &e4, nullptr);
  TreeNode e1(1, &e2, nullptr);
  vector<TreeNode*> exp = {&e6, &e7, &e1};

  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.delNodes(root, to_delete), exp);
}

TEST_F(LeetCode, test2)
{
  TreeNode n4(4);
  TreeNode n3(3);
  TreeNode n2(2, nullptr, &n3);
  TreeNode n1(1, &n2, &n4);
  TreeNode* root = &n1;

  vector<int> to_delete { 3 };

  TreeNode e4(4);
  TreeNode e2(2);
  TreeNode e1(1, &e2, &e4);
  vector<TreeNode*> exp = {&e1};

  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.delNodes(root, to_delete), exp);
}

TEST_F(LeetCode, test3)
{
  //                1
  //               / \
  //              2  3
  //             / \  \
  //            4  5   6
  //           / \  \
  //          7  8  9        // delete 1/2/5
  //
  //                 
  //                 
  //            4   9   3
  //           /         \
  //          7           6

  TreeNode e7(7);
  TreeNode e4(4, &e7, nullptr);

  TreeNode e9(9);

  TreeNode e6(6);
  TreeNode e3(3, nullptr, &e6);
  vector<TreeNode*> exp = {&e9, &e4, &e3};

  TreeNode n9(9);
  TreeNode n8(8);
  TreeNode n7(7);
  TreeNode n6(6);
  TreeNode n5(5, nullptr, &n9);
  TreeNode n4(4, &n7, &n8);
  TreeNode n3(3, nullptr, &n6);
  TreeNode n2(2, &n4, &n5);
  TreeNode n1(1, &n2, &n3);
  TreeNode* root = &n1;

  vector<int> to_delete{1, 2, 5};

  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.delNodes(root, to_delete), exp);
}

TEST_F(LeetCode, test3LeftRight)
{
  //                1
  //               / \
  //              2  3
  //             / \  \
  //            4  5   6
  //           / \  \
  //          7  8  9        // delete 1/2/5
  //
  //                 
  //                 
  //            4   9   3
  //           /         \
  //          7           6
  TreeNode e7(7);
  TreeNode e4(4, &e7, nullptr);

  TreeNode e9(9);

  TreeNode e6(6);
  TreeNode e3(3, nullptr, &e6);
  vector<TreeNode*> exp = {&e9, &e4, &e3};

  TreeNode n9(9);
  TreeNode n8(8);
  TreeNode n7(7);
  TreeNode n6(6);
  TreeNode n5(5, nullptr, &n9);
  TreeNode n4(4, &n7, &n8);
  TreeNode n3(3, nullptr, &n6);
  TreeNode n2(2, &n4, &n5);
  TreeNode n1(1, &n2, &n3);
  TreeNode* root = &n1;

  vector<int> to_delete{1, 2, 5, 8};

  for (int i = 0; i < loopNum; i++)
    EXPECT_EQ(foo.delNodesLeftRight(root, to_delete), exp);
}
