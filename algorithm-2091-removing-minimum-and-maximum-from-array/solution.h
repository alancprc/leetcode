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
  int minimumDeletions(vector<int>& nums)
  {
    const int n = nums.size();
    if (n <= 2) return n;
    int minV = 10e6, p = 0, maxV = -10e6, q = 0;
    for (int i = 0; i < n; ++i) {
      int e = nums[i];
      if (e < minV) {
        minV = e;
        p = i;
      }
      if (e > maxV) {
        maxV = e;
        q = i;
      }
    }
    if (p > q) swap(p, q);
    // 0 <= p < q < n
    return n - max({p, q - p - 1, n - 1 - q});
  }
};
