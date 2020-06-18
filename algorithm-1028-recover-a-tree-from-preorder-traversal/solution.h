#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <cstdio>
#include <queue>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int null = 0;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
 public:
  TreeNode *recoverFromPreorder(string S) { return new TreeNode(0); }
};

vector<int> print(TreeNode *tree)
{
  // middle, left, right
  queue<TreeNode *> nodes;
  vector<int> result;

  nodes.push(tree);

  while (!nodes.empty()) {
    auto ptr = nodes.front();
    nodes.pop();
    if (ptr != nullptr) {
      result.push_back(ptr->val);
      if (ptr->left != nullptr) {
        nodes.push(ptr->left);
        nodes.push(ptr->right);
      }
    }
  }
  return result;
}
