#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <cstdio>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
 public:
  int findBestValue(vector<int>& arr, int target)
  {
    sort(arr.begin(), arr.end());

    // search the first value in arr that makes diff >= 0
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      double sum =
          accumulate(arr.begin(), it, 0) + *it * distance(it, arr.end());

      if (sum >= target) {
        int rnd = round((sum - target) / distance(it, arr.end()));
        return *it - rnd;
      }
    }

    // sum of arr < target
    return arr.back();
  }

  int findBestValueV1(vector<int>& arr, int target)
  {
    sort(arr.begin(), arr.end());

    // search the first value in arr that makes diff >= 0
    auto search = find_if(arr.begin(), arr.end(), [&](int limit) {
      return this->calcSum(arr, limit) >= target;
    });

    // sum of arr < target
    if (search == arr.end()) return arr.back();

    double diff = calcSum(arr, *search) - target;
    int dis = distance(search, arr.end());
    return *search - round(diff / dis);
  }

  int findBestValueV0(vector<int>& arr, int target)
  {
    vector<int>& vec = arr;
    std::sort(vec.begin(), vec.end());

    // search the first value in vec that makes diff >= 0
    auto search =
        std::find_if(vec.begin(), vec.end(), [this, &vec, target](int limit) {
          return this->calcDiff(vec, limit, target) >= 0;
        });
    // sum of vec < target
    if (search == vec.end()) return vec.back();

    double diff = calcDiff(vec, *search, target);
    int dis = std::distance(search, vec.end());
    return *search - round(diff / dis);
  }

  int calcDiff(const vector<int>& vec, int uplimit, int target)
  {
    return calcSum(vec, uplimit) - target;
  }

  long calcSum(const vector<int>& vec, int uplimit)
  {
    auto large = std::upper_bound(vec.begin(), vec.end(), uplimit);
    return std::accumulate(vec.begin(), large, 0) +
           distance(large, vec.end()) * uplimit;
  }
};
