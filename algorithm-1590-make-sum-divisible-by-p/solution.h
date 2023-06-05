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
  // single hash map
  int minSubarray(vector<int>& nums, int p)
  {
    const int sz = nums.size();

    int sum = 0;
    for (auto e : nums) sum = (sum + e) % p;

    if (sum == 0) return 0;
    if (sz == 1) return -1;

    int minLen = sz;
    unordered_map<int, int> idxForRmd;
    idxForRmd[0] = -1;
    for (int idx = 0, rmd = 0; idx < sz; ++idx) {
      rmd            = (rmd + nums[idx]) % p;
      idxForRmd[rmd] = idx;

      if (rmd == 0) {
        minLen = min(minLen, sz - 1 - idx);
      }

      int targetRmd = (p - ((sum - rmd) % p)) % p;
#ifdef DebugPrint
      printf("\n****minLen=%i, idx=%i, num=%i, rmd=%i, target rmd=%i", minLen,
             idx, nums[idx], rmd, targetRmd);
#endif

      auto search = idxForRmd.find(targetRmd);
      if (search == idxForRmd.end()) continue;

#ifdef DebugPrint
      printf(", searched idx=%i, len=%i\n", search->second,
             idx - search->second);
#endif

      int len = idx - search->second;
      minLen  = min(minLen, len);
    }

    return minLen == sz ? -1 : minLen;
  }

  int minSubarrayUnorderedMap(vector<int>& nums, int p)
  {
    // calc sum;
    // typedef vector<int>::iterator ptr;
    // ptr itBegin = nums.begin();
    // ptr itEnd   = nums.end();

    int sum      = 0;
    const int sz = nums.size();

    for (auto e : nums) sum = (sum + e) % p;
    int remainder = sum % p;

#ifdef DebugPrint
    printf("size = %i, sum = %i, remainder = %i\n", sz, sum, remainder);
#endif
    if (remainder == 0) return 0;
    if (sz == 1) return -1;

    // calc the sum of sub array,
    // to make sum_of_sub_array % p == sum % p.
    // for (ptr it = itBegin; it != itEnd; ++it) {
    //   if (*it % p == remainder) return 1;
    // }

    unordered_map<int, vector<int> > idxForRmdL;
#ifdef DebugPrint
    printf("\nleft to right\n");
#endif
    for (int i = 0, rmd = 0; i < sz; ++i) {
      rmd = (rmd + nums[i]) % p;
      idxForRmdL[rmd].push_back(i);
#ifdef DebugPrint
      printf("%2i, ", rmd);
#endif
    }

#ifdef DebugPrint
      printf("\nright to left\n");
#endif
    unordered_map<int, vector<int> > idxForRmdR;
    for (int i = sz - 1, rmd = 0; i >= 0; --i) {
      rmd = (rmd + nums[i]) % p;
      idxForRmdR[rmd].push_back(i);
#ifdef DebugPrint
      printf("%2i, ", rmd);
#endif
    }
    // pad 0 in both ends, with index -1 and sz
    idxForRmdL[0].push_back(-1);
    idxForRmdR[0].push_back(sz);

    int minLen = sz;
    for (auto it = idxForRmdL.begin(); it != idxForRmdL.end(); ++it) {
      int rmd = it->first;

      auto searchR = idxForRmdR.find((p - rmd) % p);
      if (searchR == idxForRmdR.end()) continue;

      vector<int> idxR = searchR->second;
      vector<int> idxL = it->second;
      sort(idxR.begin(), idxR.end());
      for (auto i : idxL) {
        // ptr search = idxR.begin();
        // for (; search != idxR.end() && *search < i + 1; ++search) ;
        auto search = upper_bound(idxR.begin(), idxR.end(), i + 1);
        if (search == idxR.end()) continue;
        int len = *search - i - 1;
        minLen  = min(minLen, len);
        // minLen = len < minLen ? len : minLen;  // min(minLen, len);
      }
    }
    return minLen == sz ? -1 : minLen;
  }

  int minSubarrayUnorderedMultiMap(vector<int>& nums, int p)
  {
    // calc sum;
    // typedef vector<int>::iterator ptr;
    // ptr itBegin = nums.begin();
    // ptr itEnd   = nums.end();

    int sum      = 0;
    const int sz = nums.size();

    for (auto e : nums) sum = (sum + e) % p;
    int remainder = sum % p;

#ifdef DebugPrint
    printf("size = %i, sum = %i, remainder = %i\n", sz, sum, remainder);
#endif
    if (remainder == 0) return 0;
    if (sz == 1) return -1;

    // calc the sum of sub array,
    // to make sum_of_sub_array % p == sum % p.
    // for (ptr it = itBegin; it != itEnd; ++it) {
    //   if (*it % p == remainder) return 1;
    // }

    unordered_multimap<int, int> idxForRmdL;
#ifdef DebugPrint
      printf("\nleft to right\n");
#endif
    for (int i = 0, rmd = 0; i < sz; ++i) {
      rmd = (rmd + nums[i]) % p;
      idxForRmdL.emplace(rmd, i);
#ifdef DebugPrint
      printf("%2i, ", rmd);
#endif
    }

#ifdef DebugPrint
      printf("\nright to left\n");
#endif
    unordered_multimap<int, int> idxForRmdR;
    for (int i = sz - 1, rmd = 0; i >= 0; --i) {
      rmd = (rmd + nums[i]) % p;
      idxForRmdR.emplace(rmd, i);
#ifdef DebugPrint
      printf("%2i, ", rmd);
#endif
    }
    // pad 0 in both ends, with index -1 and sz
    idxForRmdL.emplace(0, -1);
    idxForRmdR.emplace(0, sz);

    int minLen = sz;
    for (auto it = idxForRmdL.begin(); it != idxForRmdL.end(); ++it) {
      int rmd = it->first;

      auto searchR = idxForRmdR.equal_range((p - rmd) % p);
      vector<int> idxR;
      for (auto itR = searchR.first; itR != searchR.second; ++itR) {
        idxR.push_back(itR->second);
      }
      if (idxR.empty()) continue;

      vector<int> idxL;
      auto searchL = idxForRmdL.equal_range(rmd);
      for (auto itL = searchL.first; itL != searchL.second; ++itL) {
        idxL.push_back(itL->second);
      }
      sort(idxR.begin(), idxR.end());
      for (auto i : idxL) {
        // ptr search = idxR.begin();
        // for (; search != idxR.end() && *search < i + 1; ++search) ;
        auto search = upper_bound(idxR.begin(), idxR.end(), i + 1);
        if (search == idxR.end()) continue;
        int len = *search - i - 1;
        minLen  = min(minLen, len);
        // minLen = len < minLen ? len : minLen;  // min(minLen, len);
      }
    }
    return minLen == sz ? -1 : minLen;
  }
  
  int minSubarrayTimeOut(vector<int>& nums, int p)
  {
    // calc sum;
    typedef vector<int>::iterator ptr;
    ptr itBegin       = nums.begin();
    ptr itEnd         = nums.end();

    long long int sum = 0;
    const int sz      = nums.size();

    for (auto e : nums) sum += e;
    int remainder = sum % p;

#ifdef DebugPrint
    printf("size = %i, sum = %lli, remainder = %i\n", sz, sum, remainder);
#endif
    if (remainder == 0) return 0;
    if (sz == 1) return -1;

    // calc the sum of sub array,
    // to make sum_of_sub_array % p == sum % p.
    for (ptr it = itBegin; it != itEnd; ++it) {
      if (*it % p == remainder) return 1;
    }

    for (int i = 2; i < sz - 1; ++i) {
      long long int subSum = 0;
      ptr ptrL             = itBegin;
      ptr ptrR             = ptrL + i;
      for (ptr it = ptrL; it != itEnd && it != ptrR; ++it) subSum += *it;
      if (subSum % p == remainder) return i;
      do {
        subSum += *ptrR - *ptrL;
        ++ptrL, ++ptrR;
        if (subSum % p == remainder) return i;
      } while (ptrR < itEnd);
    }

    return -1;
  }
};
