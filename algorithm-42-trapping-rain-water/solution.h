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
  int trap(vector<int>& height)
  {
    // l, r starting from left/right to middle
    // find the first non zero
    // the min(*l, *r) is the level for next heights
#ifdef DebugPrint
    for (auto e : height) printf("%3i,", e);
    cout << endl;
    for (int i = 0; i < height.size(); ++i) {
      printf("%3i,", i);
    }
    cout << endl;
#endif
    int l = 0, r = height.size() - 1;
    int currH = 0;
    int sum = 0;
    while (l < r) {
      if (height[l] <= currH) {
        sum += currH - height[l];
#ifdef DebugPrint
        printf("currH=%i, l=%i, r=%i, height[l]=%i, height[r]=%i, sum=%i\n", currH, l, r, height[l], height[r], sum);
#endif
        ++l;
        continue;
      }
      if (height[r] <= currH) {
        sum += currH - height[r];
#ifdef DebugPrint
        printf("currH=%i, l=%i, r=%i, height[l]=%i, height[r]=%i, sum=%i\n", currH, l, r, height[l], height[r], sum);
#endif
        --r;
        continue;
      }
      currH = min(height[l], height[r]);
#ifdef DebugPrint
      printf("currH=%i, l=%i, r=%i, height[l]=%i, height[r]=%i, sum=%i\n", currH, l, r, height[l], height[r], sum);
#endif
    }
    return sum;
  }
};
