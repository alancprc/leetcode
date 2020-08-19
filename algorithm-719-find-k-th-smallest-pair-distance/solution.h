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

#include "print-time.h"

using namespace std;

class Solution
{
 private:
  vector<int> nums;

 public:
  int smallestDistancePair(vector<int>& nums, int k)
  {
    // save number:frequency into map<value, freq>
    PrintTime pt(__func__);
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
    cout << sortedDistance.size() << endl;
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
    int size = nums.size();
    vector<int> dist;
    dist.reserve(size * (size - 1) / 2);

    for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
      for (auto it2 = it1 + 1; it2 != nums.end(); ++it2) {
        dist.push_back(std::abs(*it1 - *it2));
      }
    }
    auto kth = dist.begin() + k - 1;
    std::nth_element(dist.begin(), kth, dist.end());
    return *kth;
  }
};
