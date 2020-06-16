#pragma once

#include <algorithm>
#include <cassert>
#include <climits>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    vector<int> nums;
    nums.reserve(nums1.size() + nums2.size());
    nums.insert(nums.begin(), nums1.begin(), nums1.end());
    nums.insert(nums.begin(), nums2.begin(), nums2.end());

    auto size = nums.size();
    auto mid1 = nums.begin() + size / 2;
    auto mid2 = nums.begin() + (size - 1) / 2;

    nth_element(nums.begin(), mid1, nums.end());
    if (mid1 != mid2) nth_element(nums.begin(), mid2, nums.end());
    return (*mid1 + *mid2) / 2.0;
  }
};

