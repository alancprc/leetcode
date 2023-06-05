#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define PrintTimeOff
// #define DebugPrint
#include "print-time.h"

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right)
  {
  }
};

void PrintTo(TreeNode* root, ::std::ostream* os = &cout)
{
  *os << "[";
  std::stack<TreeNode*> nodes;

  if (root != nullptr) nodes.push(root);

  while (!nodes.empty()) { // do not push nullptr into nodes
    auto n = nodes.top();
    nodes.pop();
    *os << n->val;
    if (n == nullptr) continue;
    if (n->right == nullptr && n->left == nullptr) continue;

    if (n->right != nullptr) {
      nodes.push(n->right);
    }
    if (n->left != nullptr) {
      nodes.push(n->left);
    }
  }
  *os << "]";
#ifdef DebugPrint
  *os << "\n";
#endif
}

class Solution
{
 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
  {
    vector<TreeNode*> result;
    if (root == nullptr) return result;

    std::unordered_set<int> valToDel(to_delete.begin(), to_delete.end());
    std::set<TreeNode*> trees;
    std::stack<TreeNode*> nodes;
    trees.insert(root);

    // remove node:
    //      erase from valToDel
    //      erase from trees
    //      insert left/right into trees
    //      insert left/right into nodes if not nullptr    -- common
    // keep node:
    //      insert left/right into nodes if not nullptr    -- common
#ifdef DebugPrint
    PrintTo(root);
#endif

    nodes.push(root);
    while (!valToDel.empty() && !nodes.empty()) {
      auto node = nodes.top();
      nodes.pop();
      if (node == nullptr) continue;
#ifdef DebugPrint
      printf("node val, %i\n", node->val);
#endif

      nodes.push(node->right);
      nodes.push(node->left);
      // 1, 2, 3
      for (auto ptr : {&node, &node->left, &node->right}) {
        auto& son = *ptr;
        if (son == nullptr) continue;

        if (valToDel.count(son->val)) {
          valToDel.erase(son->val);
          trees.erase(son);
          for (auto gson : {son->right, son->left}) {
            if (gson == nullptr) continue;
            trees.insert(gson);
            nodes.push(gson);
          }
          son = nullptr;
        }
#ifdef DebugPrint
        for (auto r : trees) PrintTo(r);
#endif
      }
    }
    trees.erase(nullptr);
    for (auto e : trees) {
      result.push_back(e);
    }
    return result;
  }
  vector<TreeNode*> delNodesLeftRight(TreeNode* root, vector<int>& to_delete)
  {
    vector<TreeNode*> result;
    if (root == nullptr) return result;

    std::unordered_set<int> valToDel(to_delete.begin(), to_delete.end());
    std::set<TreeNode*> trees;
    std::stack<TreeNode*> nodes;
    trees.insert(root);

    // remove node:
    //      erase from valToDel
    //      erase from trees
    //      insert left/right into trees

    // delete root node, handle only once
    if (valToDel.count(root->val)) {
      valToDel.erase(root->val);
      trees.erase(root);
      trees.insert(root->right);
      trees.insert(root->left);
    }

    nodes.push(root);
    while (!valToDel.empty() && !nodes.empty()) {
      auto node = nodes.top(); nodes.pop();

      if (node == nullptr) continue;
#ifdef DebugPrint
      printf("node val, %i\n", node->val);
#endif
      nodes.push(node->right);
      nodes.push(node->left);

      if (node->right != nullptr && valToDel.count(node->right->val)) {
        valToDel.erase(node->right->val);
        trees.erase(node->right);
        for (auto sson : {node->right->right, node->right->left}) {
          if (sson == nullptr) continue;
          trees.insert(sson);
          nodes.push(sson);
        }
        node->right = nullptr;
      }
      if (node->left != nullptr && valToDel.count(node->left->val)) {
        valToDel.erase(node->left->val);
        trees.erase(node->left);
        for (auto sson : {node->left->right, node->left->left}) {
          if (sson == nullptr) continue;
          trees.insert(sson);
          nodes.push(sson);
        }
        node->left = nullptr;
      }
#ifdef DebugPrint
      for (auto r : trees) PrintTo(r);
#endif
    }
    trees.erase(nullptr);
    for (auto e : trees) {
      result.push_back(e);
    }
    return result;
  }
};
