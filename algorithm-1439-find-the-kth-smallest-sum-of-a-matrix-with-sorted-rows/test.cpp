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
  vector<vector<int> > mat = {{1, 3, 11}, {2, 4, 6}};
#ifdef PrintElement
  cout << "mat:\n";
  for (auto& row : mat) {
    cout << "[";
    for (auto& e : row) {
      printf("%4i, ", e);
    }
    cout << "]\n";
  }
  cout << endl << endl;
#endif
  for (int i = 0; i < loopNum; i++) {
    EXPECT_EQ(foo.kthSmallest(mat, 5), 7);
  }
}

TEST_F(LeetCode, test2)
{
  vector<vector<int> > mat = {{1, 3, 11}, {2, 4, 6}};
#ifdef PrintElement
  cout << "mat:\n";
  for (auto& row : mat) {
    cout << "[";
    for (auto& e : row) {
      printf("%4i, ", e);
    }
    cout << "]\n";
  }
  cout << endl << endl;
#endif
  for (int i = 0; i < loopNum; i++) {
    EXPECT_EQ(foo.kthSmallest(mat, 9), 17);
  }
}

TEST_F(LeetCode, test3)
{
  vector<vector<int> > mat = {{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
#ifdef PrintElement
  cout << "mat:\n";
  for (auto& row : mat) {
    cout << "[";
    for (auto& e : row) {
      printf("%4i, ", e);
    }
    cout << "]\n";
  }
  cout << endl << endl;
#endif
  for (int i = 0; i < loopNum; i++) {
    EXPECT_EQ(foo.kthSmallest(mat, 7), 9);
  }
}

TEST_F(LeetCode, test4)
{
  vector<vector<int> > mat = {{1, 1, 10}, {2, 2, 9}};
#ifdef PrintElement
  cout << "mat:\n";
  for (auto& row : mat) {
    cout << "[";
    for (auto& e : row) {
      printf("%4i, ", e);
    }
    cout << "]\n";
  }
  cout << endl << endl;
#endif
  for (int i = 0; i < loopNum; i++) {
    EXPECT_EQ(foo.kthSmallest(mat, 7), 12);
  }
}

TEST_F(LeetCode, test29)
{
  vector<vector<int> > mat = {
      {5, 12, 29, 40, 85, 96, 99},  {37, 37, 40, 45, 72, 86, 91},
      {4, 43, 50, 63, 76, 93, 100}, {45, 56, 69, 90, 91, 93, 94},
      {4, 6, 24, 51, 60, 76, 88},   {1, 14, 29, 52, 62, 95, 96},
      {19, 47, 49, 54, 66, 68, 72}, {24, 25, 59, 60, 82, 92, 96},
      {10, 25, 29, 38, 56, 91, 96}, {12, 29, 36, 65, 69, 79, 98}};
#ifdef PrintElement
  cout << "mat:\n";
  for (auto& row : mat) {
    cout << "[";
    for (auto& e : row) {
      printf("%4i, ", e);
    }
    cout << "]\n";
  }
  cout << endl << endl;
#endif
  for (int i = 0; i < loopNum; i++) {
    EXPECT_EQ(foo.kthSmallest(mat, 50), 177);
  }
}

TEST_F(LeetCode, test29_1)
{
  vector<vector<int> > mat = {
      {5, 12, 29, 40, 85, 96, 99},  {37, 37, 40, 45, 72, 86, 91},
      {4, 43, 50, 63, 76, 93, 100}, {45, 56, 69, 90, 91, 93, 94},
      {4, 6, 24, 51, 60, 76, 88},   {1, 14, 29, 52, 62, 95, 96},
      {19, 47, 49, 54, 66, 68, 72}, {24, 25, 59, 60, 82, 92, 96},
      {10, 25, 29, 38, 56, 91, 96}, {12, 29, 36, 65, 69, 79, 98}};
#ifdef PrintElement
  cout << "mat:\n";
  for (auto& row : mat) {
    cout << "[";
    for (auto& e : row) {
      printf("%4i, ", e);
    }
    cout << "]\n";
  }
  cout << endl << endl;
#endif
  for (int i = 0; i < loopNum; i++) {
    EXPECT_EQ(foo.kthSmallestForce(mat, 50), 177);
  }
}
