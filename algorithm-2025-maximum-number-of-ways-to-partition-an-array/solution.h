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
  int waysToPartition(vector<int>& nums, int k)
  {
    // if do not use k
    // calc sum/prefixSum
    // find prefixSum * 2 = sum;
    long long int sum = 0;
    unordered_map<long long int, int> prefix;
    // add suffix, except nums[0]
    unordered_map<long long int, int> suffix;
    for (int i = nums.size() -1; i > 0; --i) {
      sum += nums[i];
      ++suffix[sum];
    }
#ifdef DebugPrint
    for (auto it : suffix) {
      printf("suffix key=%lli, val=%i\n", it.first, it.second);
    }
#endif
    sum += nums.front();
    int cnt = 0;
    if (sum % 2 == 0) cnt = suffix.count(sum / 2) ? suffix[sum / 2] : 0;

    // if replace nums[i] with k, just to remove at the begin of for-loop
    ++suffix[sum];
    long long int sumPre = 0;
    long long int sumPost = sum;
    for (size_t i = 0; i < nums.size(); ++i) {
      // update suffix
      --suffix[sumPost];
      if (suffix[sumPost] == 0) suffix.erase(sumPost);
      sumPost -= nums[i];

      int sum1 = sum + k - nums[i];
      if (sum1 % 2 == 0) {
        // pivot >= k
        int cnt1 = prefix.count(sum1 / 2) ? prefix[sum1 / 2] : 0;
        // pivot < k
        int cnt2 = suffix.count(sum1 / 2) ? suffix[sum1 / 2] : 0;
        cnt      = max(cnt, cnt1 + cnt2);
#ifdef DebugPrint
        printf("i=%2li, cnt1=%i, cnt2=%i\n", i, cnt1, cnt2);
        printf("prefix\n");
        for (auto it : prefix) {
          printf("\tkey=%lli, val=%i\n", it.first, it.second);
        }
        printf("suffix\n");
        for (auto it : suffix) {
          printf("\tkey=%lli, val=%i\n", it.first, it.second);
        }
#endif
      }
      // update prefix
      sumPre += nums[i];
      ++prefix[sumPre];
    }
    return cnt;
  }
};
