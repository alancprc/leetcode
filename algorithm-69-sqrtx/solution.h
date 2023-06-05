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
  int mySqrt(int x)
  {
    if (x < 2) return x;
    // for x in range [4^(n), 4^(n+1)]
    // the sqrt(x) will be in range [2^n, 2^(n+1)]
    // 4, n = 1, rtL = 2, rtR = 4
    // 8, n = 1, rtL = 2, rtR = 4
    // 16, n = 2, rtL = 4, rtR = 8
    int y = x;
    int n = 0;
    while ((y >>= 2) >= 1) {
      n += 1;
    }
    int rtL = (1 << n);
    int rtR = min(x, 2 * rtL);
    rtR     = min(rtR, 46340);
    // printf("x=%i, n=%i, rtL=%i, rtR=%i\n", x, n, rtL, rtR);
    while (rtL < rtR) {
      long long int rt = (rtL + rtR + 1) / 2;
      if (rt * rt > x)
        rtR = rt - 1;
      else
        rtL = rt;
    }
    return rtL;
  }
  int mySqrt1(int x)
  {
    int rtL = 0;
    int rtR = min(x, 46340);
    while (rtL < rtR) {
      int rt = (rtL + rtR + 1) / 2;
      if (rt * rt > x)
        rtR = rt - 1;
      else
        rtL = rt;
    }
    return rtL;
  }
};
