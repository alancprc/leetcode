#pragma once

#include <algorithm>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cstdio>

using namespace std;

class Solution
{
 public:
  int climbStairs(int n)
  {
    if (n < 2) return 1;

    int pre1 = 1;
    int pre2 = 1;
    int result = 0;
    for (; n > 1; --n) {
      result = pre1 + pre2;
      pre1 = pre2;
      pre2 = result;
    }
    return result;
  }
};
