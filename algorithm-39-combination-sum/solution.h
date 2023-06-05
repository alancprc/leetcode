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
  vector<vector<int> > combinationSum(vector<int>& candidates, int target)
  {
    vector<vector<int> > result;
    // min -> max
    std::sort(candidates.begin(), candidates.end());
    // remove candidate larger than target
    
    // find the largest candidate < target
    // for [2, target]
    result.reserve(target + candidates.size());
    return result;
  }
  vector<vector<int> > func(vector<int> candidates, int target)
  {
    return combinationSum(candidates, target);
  }
};
