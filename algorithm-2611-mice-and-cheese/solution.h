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

class Solution
{
 public:
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
  {
    const int n = reward1.size();
    if (k > n / 2) {
      swap(reward1, reward2);
      k = n - k;
    }
    // use map to save the largest k reward1-reward2 values
    int sum = 0;
    map<int, int> gaps;
    int gapCnt = 0;  // sum of values of gaps
    for (int i = 0; i < n; ++i) {
      sum += reward2[i];
      int gap = reward1[i] - reward2[i];
      if (gapCnt < k) {
        ++gaps[gap];
        ++gapCnt;
        continue;
      }
      auto it = gaps.begin();  // least gap value
      if (gap < it->first) continue;

      ++gaps[gap];
      --(it->second);
      if (it->second == 0) gaps.erase(it);
    }
    for (auto it = gaps.rbegin(); k > 0 && it != gaps.rend(); ++it) {
      int gap = it->first;
      int cnt = it->second;
#ifdef DebugPrint
      printf("sum=%i, gap=%i, cnt=%i\n", sum, gap, cnt);
#endif
      sum += gap * min(cnt, k);
      k -= cnt;
    }
    return sum;
  }
  int miceAndCheeseKeepAll(vector<int>& reward1, vector<int>& reward2, int k)
  {
    const int n = reward1.size();
    // if k < n/2;
    // use map to save the largest k reward1-reward2 values
    int sum = 0;
    map<int, int> gaps;
    for (int i = 0; i < n; ++i) {
      sum += reward2[i];
      int gap = reward1[i] - reward2[i];
      ++gaps[gap];
    }
    for (auto it = gaps.rbegin(); k > 0 && it != gaps.rend(); ++it) {
      int gap = it->first;
      int cnt = it->second;
#ifdef DebugPrint
      printf("sum=%i, gap=%i, cnt=%i\n", sum, gap, cnt);
#endif
      sum += gap * min(cnt, k);
      k -= cnt;
    }
    return sum;
  }
};
