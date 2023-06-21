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
#include "print-time.h"

using namespace std;

class Solution
{
 public:
  int smallestDistancePairDualIndex(vector<int>& nums, int k)
  {
    // sort nums
    std::sort(nums.begin(), nums.end());

    int disL = 0 - 1;
    int disR = nums.back() + 1;

    size_t sz = nums.size();

    for (; disL + 1 < disR;) {
      int disMid = (disL + disR) / 2.0;
      // calc the count of distance pair that <= disMid.
      int cnt = 0;
      for (size_t itL = 0, itR = itL; itL < sz; ++itL) {
        for (; itR < sz && nums[itR] - nums[itL] <= disMid; ++itR)
          ;
        cnt += itR - itL - 1;
      }

      if (cnt < k) {
        disL = disMid;
      } else {
        disR = disMid;
      }
    }
    return disR;
  }

  int smallestDistancePairDualPointer(vector<int>& nums, int k)
  {
    // sort nums
    std::sort(nums.begin(), nums.end());

    int disL = 0 - 1;
    int disR = nums.back() + 1;

    typedef int* ptr;
    ptr itBegin = &nums.front();
    ptr itEnd   = &nums.back() + 1;

    for (; disL + 1 < disR;) {
      int disMid = (disL + disR) / 2.0;
      // calc the count of distance pair that <= disMid.
      int cnt = 0;
      for (ptr itL = itBegin, itR = itL; itL < itEnd; ++itL) {
        for (; itR < itEnd && *itR - *itL <= disMid; ++itR)
          ;
        cnt += itR - itL - 1;
      }

      if (cnt < k) {
        disL = disMid;
      } else {
        disR = disMid;
      }
    }
    return disR;
  }

  int smallestDistancePairDualIter(vector<int>& nums, int k)
  {
    // sort nums
    std::sort(nums.begin(), nums.end());

    int disL = 0 - 1;
    int disR = nums.back() + 1;

    typedef vector<int>::iterator ptr;
    ptr itBegin = nums.begin();
    ptr itEnd   = nums.end();

    for (; disL + 1 < disR;) {
      int disMid = (disL + disR) / 2.0;
      // calc the count of distance pair that <= disMid.
      int cnt = 0;
      for (ptr itL = itBegin, itR = itL; itL < itEnd; ++itL) {
        for (; itR < itEnd && *itR - *itL <= disMid; ++itR)
          ;
        cnt += itR - itL - 1;
        // int n   = itR - itL - 1;
        // printf("**itL = %li, itR = %li, cnt = %i, total = %i\n", itL - itBegin, itR - itBegin, n, cnt);
      }

      // printf("disL = %i, disR = %i, dis <= %i, cnt = %i\n", disL, disR, disMid, cnt);

      if (cnt < k) {
        disL = disMid;
      } else {
        disR = disMid;
      }
    }
    return disR;
  }

  int smallestDistancePairSample(vector<int>& nums, int k)
  {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back(), n = nums.size();
    while (left < right) {
      int mid = (left + right) >> 1, cnt = 0;
      for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && nums[j] - nums[i] <= mid) ++j;
        cnt += j - i - 1;
      }
      if (cnt < k)
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }

  int smallestDistancePairRs(vector<int>& nums, int k)
  {
    // sort nums
    sort(nums.begin(), nums.end());
    // cout << "[";
    // for (auto e : nums) cout << e << ", ";
    // cout << "]" << endl;

    // for short
    typedef vector<int>::iterator Iter;
    Iter itBegin = nums.begin();
    Iter itEnd   = nums.end();

    int disLeft    = -1;                              // less than k
    int disRight   = nums.back() - nums.front() + 1;  // more than k
    int disMid     = (disLeft + disRight) / 2;
    int totalPairs = 0;

    while (disLeft + 1 < disRight) {
      disMid = (disLeft + disRight) / 2;
      // if (disMid == disLeft || disMid == disRight) break;

      // printf("*** disM = %i ***\n", disMid);
      totalPairs = 0;

      // count pairs whose distance <= disMid
      Iter left  = nums.begin();
      Iter right = left;
      do {
        // find the location of first number > *left + distance
        right = upper_bound(left, itEnd, *left + disMid);
        int n = std::distance(left, right) - 1;
        int pairs = n;
        totalPairs += pairs;

        // printf( "\tleft = %li, *left = %i, right = %li, numbers = %i, pairs = %i, total = %i\n", distance(itBegin, left), *left, distance(itBegin, right), n, pairs, totalPairs);

        // increase left
        // left      = upper_bound(left, itEnd, *left);
        ++left;
      } while (left != itEnd);

      // printf("k = %i, disL = %i, disR = %i, disM < %i, pairs = %i\n", k, disLeft, disRight, disMid, totalPairs);
      if (totalPairs < k) {
        disLeft = disMid;
      } else { //if (totalPairs > k) {
        disRight = disMid;
      //} else {
      //  return disMid;
      }
    }
    // printf("k = %i, disL = %i, disR = %i, disM < %i, pairs = %i ** final **\n", k, disLeft, disRight, disMid, totalPairs);
    return disRight;
    // return totalPairs > k ? disRight : disLeft;
  }
  int smallestDistancePairBinaryCount(vector<int>& nums, int k)
  {
    // sort nums
    sort(nums.begin(), nums.end());
    // cout << "[";
    // for (auto e : nums) cout << e << ", ";
    // cout << "]" << endl;

    // for short
    typedef vector<int>::iterator Iter;
    Iter itBegin = nums.begin();
    Iter itEnd   = nums.end();

    int disLeft    = -1;                           // less than k
    int disRight   = nums.back() - nums.front() + 1;  // more than k
    int disMid     = (disLeft + disRight) / 2;
    int totalPairs = 0;

    while (disLeft + 1 < disRight) {
      disMid = (disLeft + disRight) / 2;
      // if (disMid == disLeft || disMid == disRight) break;

      printf("*** disM = %i ***\n", disMid);
      totalPairs = 0;

      // count pairs whose distance <= disMid
      Iter left  = nums.begin();
      Iter right = left;
      Iter lastRight = right;
      do {
        // find the location of first number > *left + distance
        right = upper_bound(left, itEnd, *left + disMid);
        int n = std::distance(left, right);
        int pairs = n * (n - 1) / 2;

        int common = std::distance(left, lastRight);
        if (common > 0) pairs -= common * (common - 1) / 2;

        totalPairs += pairs;

        printf( "\tleft = %li, *left = %i, right = %li, numbers = %i, pairs = %i, total = %i\n", distance(itBegin, left), *left, distance(itBegin, right), n, pairs, totalPairs);

        // increase left/right/lastRight
        left      = upper_bound(left, itEnd, *left);
        lastRight = right;
      } while (left != itEnd && right != itEnd);

      printf("k = %i, disL = %i, disR = %i, disM < %i, pairs = %i\n", k, disLeft, disRight, disMid, totalPairs);
      if (totalPairs < k) {
        disLeft = disMid;
      } else { //if (totalPairs > k) {
        disRight = disMid;
      //} else {
      //  return disMid;
      }
    }
    printf("k = %i, disL = %i, disR = %i, disM < %i, pairs = %i ** final **\n", k, disLeft, disRight, disMid, totalPairs);
    return disRight;
    // return totalPairs > k ? disRight : disLeft;
  }

  int smallestDistancePair4(vector<int>& nums, int k)
  {
    // save number:frequency into map<value, freq>
    std::sort(nums.begin(), nums.end());

    unordered_map<int, int> freq;
    for (auto n : nums) ++freq[n];

    if (freq.size() > nums.size() / 3)
      return smallestDistancePairLowRepeat(nums, k);
    else
      return smallestDistancePairHighRepeat(k, freq);
  }

  int smallestDistancePairLowRepeat(vector<int>& nums, int k)
  {
    int size = nums.size();
    vector<int> dist(size * (size - 1) / 2);

    auto it = dist.begin();
    for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
      for (auto it2 = it1 + 1; it2 != nums.end(); ++it2) {
        *(it++) = *it2 - *it1;
      }
    }

    auto kth = dist.begin() + k - 1;
    std::nth_element(dist.begin(), kth, dist.end());
    return *kth;
  }

  int smallestDistancePairHighRepeat(int k, unordered_map<int, int> freq)
  {
    // get distance map <dis, repeat=m*n>
    // map<int, int> dist;
    unordered_map<int, int> dist;
    int size = freq.size();
    dist.reserve(size * (size - 1) / 2);
    for (auto it1 = freq.begin(); it1 != freq.end(); ++it1) {
      dist[0] += it1->second * (it1->second - 1) / 2;

      auto it2 = it1;
      for (++it2; it2 != freq.end(); ++it2) {
        dist[std::abs(it1->first - it2->first)] += it1->second * it2->second;
      }
    }

    // search distance map
    // while k > freq, k -= repeat, iterator+=1;
    map<int, int> sortedDistance(dist.begin(), dist.end());
    auto it = sortedDistance.begin();
    while (k > it->second) {
      k -= it->second;
      ++it;
    }
    return it->first;
  }

  int smallestDistancePair3(vector<int>& nums, int k)
  {
    // save number:frequency into map<value, freq>
    PrintTime pt;

    std::sort(nums.begin(), nums.end());
    pt.Snap("sort nums");

    unordered_map<int, int> freq;
    for (auto n : nums) ++freq[n];
    pt.Snap("create hash map for frequency");

    // get distance map <dis, repeat=m*n>
    // map<int, int> dist;
    // unordered_map<int, int> dist;
    vector<int> dist;
    int size = freq.size();
    dist.reserve(size * (size - 1 ) / 2 );
    pt.Snap("initialize dist hash map");

    for (auto it1 = freq.begin(); it1 != freq.end(); ++it1) {
      // dist[0] += it1->second * (it1->second - 1) / 2;
      dist.insert(dist.end(), it1->second * (it1->second - 1) / 2, 0);
    }
    pt.Snap("count distance 0");

    for (auto it1 = freq.begin(); it1 != freq.end(); ++it1) {
      auto it2 = it1;
      for (++it2; it2 != freq.end(); ++it2) {
        // dist[std::abs(it1->first - it2->first)] += it1->second * it2->second;
        dist.insert(dist.end(), it1->second * it2->second,
                    std::abs(it2->first - it1->first));
      }
    }
    pt.Snap("create hash map for distance");

    auto kth = dist.begin() + k - 1;
    std::nth_element(dist.begin(), kth, dist.end());
    pt.Snap("calc distance");
    return *kth;
  }

  int smallestDistancePair2(vector<int>& nums, int k)
  {
    PrintTime pt;

    std::sort(nums.begin(), nums.end());
    pt.Snap("sort nums");

    // save number->frequency into map<value, freq>
    unordered_map<int, int> freq;
    for (auto n : nums) ++freq[n];
    pt.Snap("create hash map for frequency");

    // get distance map <dis, repeat=m*n>
    // map<int, int> dist;
    unordered_map<int, int> dist;
    int size = freq.size();
    dist.reserve(size * (size - 1 ) / 2 );
    for (auto it1 = freq.begin(); it1 != freq.end(); ++it1) {
      dist[0] += it1->second * (it1->second - 1) / 2;

      auto it2 = it1;
      for (++it2; it2 != freq.end(); ++it2) {
        dist[std::abs(it1->first - it2->first)] += it1->second * it2->second;
      }
    }
    pt.Snap("create hash map for distance");

    // search distance map
    // while k > freq, k -= repeat, iterator+=1;
    map<int, int> sortedDistance(dist.begin(), dist.end());
    auto it = sortedDistance.begin();
    while (k > it->second) {
      k -= it->second;
      ++it;
    }
    pt.Snap("calc distance");
    return it->first;
  }

  int smallestDistancePair1(vector<int>& nums, int k)
  {
    PrintTime pt;

    std::sort(nums.begin(), nums.end());
    pt.Snap("sort nums");

    int size = nums.size();
    vector<int> dist(size * (size - 1) / 2);
    pt.Snap("initialize");

    auto it = dist.begin();
    for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
      for (auto it2 = it1 + 1; it2 != nums.end(); ++it2) {
        // dist.push_back(std::abs(*it2 - *it1));
        *(it++) = (*it2 - *it1);
      }
    }
    pt.Snap("calc all distance");

    auto kth = dist.begin() + k - 1;
    std::nth_element(dist.begin(), kth, dist.end());
    pt.Snap("calc kth distance");
    return *kth;
  }
  int smallestDistancePair(vector<int>& nums, int k)
  {
    // return smallestDistancePairDualIndex(nums, k);
    // return smallestDistancePairDualPointer(nums, k);
    return smallestDistancePairDualIter(nums, k);
  }
};
