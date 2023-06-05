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
  int maximumTastiness(vector<int>& price, int k)
  {
    // sort
    std::sort(price.begin(), price.end());
    const int maxT = price.back() - price.front();
    // quick calc for k=2
    if (k == 2) return maxT;

    // for k > 2, max tastiness is in range [0, maxT/(k-1)]
    // do binary search for tastiness, for each possible tastiness T:
    //  1. save the lowest/first price as lastPrice, and counter cnt = 1
    //  2. iterate through prices, if current price p is greater or equal `lastPrice + T`
    //      increase counter cnt, and update lastPrice to current price p
    //  3. if cnt >= k, then current searched tastiness T is a possible one
    int tL = 0, tR = maxT / (k - 1);
    while (tL < tR) {
      int tM  = (tL + tR + 1) / 2;
      int cnt = 1;
      int last = price.front();
      for (auto it = price.begin(); cnt < k && it != price.end(); ++it) {
        if (*it >= last + tM) {
          cnt += 1;
          last = *it;
        }
      }

      if (cnt < k)
        tR = tM - 1;
      else
        tL = tM;
    }
    return tL;
  }

  int maximumTastinessCalcAll(vector<int>& price, int k)
  {
    std::sort(price.begin(), price.end());
    vector<int> gap;
    gap.reserve(price.size() - 1);
    std::adjacent_difference(price.begin(), price.end(), gap.begin());
    
    return k;
  }
};
