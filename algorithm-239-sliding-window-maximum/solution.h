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
#include <set>
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
  // save window with map
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    vector<int> result;
    result.reserve(nums.size() - k + 1);

    typedef vector<int>::iterator ptr;
    ptr itL = nums.begin();
    ptr itR = itL + k;

    map<int, int> window;
    for (auto it = itL; it != itR; ++it) ++window[*it];

    result.push_back((window.rbegin())->first);
    for (; itR < nums.end(); ++itL, ++itR) {
      int newVal = *itR;
      int oldVal = *itL;

      ++window[newVal];
      --window[oldVal];
      if (window[oldVal] == 0) window.erase(oldVal);

      result.push_back((window.rbegin())->first);
    }
    return result;
  }
  vector<int> maxSlidingWindowMaxElement(vector<int>& nums, int k)
  {
    vector<int> result;
    result.reserve(nums.size() - k + 1);

    typedef vector<int>::iterator ptr;
    ptr itL = nums.begin();
    ptr itR = itL + k;
    ptr itM = max_element(itL, itR);
    result.push_back(*itM);
    for (; itR < nums.end(); ++itR) {
      int newVal = *itR;
      ++itL;
      if (newVal < *itM && itM < itL) {
        itM = max_element(itL, itR + 1);
      } else if (newVal >= *itM) {
        itM = itR;
      }
      result.push_back(*itM);
    }
    return result;
  }
};
