#pragma once

#include <condition_variable>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    // sort
    // sorted index => original index
    //
    // for sorted vector
    //  p1 = begin
    //  p2 = end - 1;
    //  loop 
    //      if *p1 + *p2 >  target
    //          p2--
    //      else if *p1 + *p2 < target
    //          p1++
    //      else break
    // return index of p1/p2;
    vector<vector<int>::iterator> sorted_it(nums.size());
    {
      auto dest = sorted_it.begin();
      for (auto it = nums.begin(); it != nums.end(); ++it, ++dest) {
        *dest = it;
      }
    }
    typedef vector<int>::iterator it_t ;
    std::sort(sorted_it.begin(), sorted_it.end(), [](it_t a, it_t b) {return *a < *b; });

    auto begin = sorted_it.begin();
    auto end = sorted_it.end() - 1;
    while (true) {
      if (**begin + **end < target)
        ++begin;
      else if (**begin + **end > target)
        --end;
      else
        break;
    }
    vector<int> result(2);
    result.at(0) = std::distance(nums.begin(), *begin);
    result.at(1) = std::distance(nums.begin(), *end);
    std::sort(result.begin(), result.end());
    return result;

  }
};

