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
//#define PrintElement

#include "print-time.h"

using namespace std;

class Solution
{
 public:
  // eleMid = relative to first element in each row
  int kthSmallest(vector<vector<int> >& mat, int k)
  {
    const int maxN = 40;
    // element left/right value
    int eleL = 0, eleR = 0, eleMid = 0;
    for (auto& row : mat) {
      int m = row.back() - row.front();
      eleR  = m > eleR ? m : eleR;
    }
    typedef vector<int>::iterator ptr;

    while (eleL + 1 < eleR) {
      eleMid = (eleL + eleR) / 2;
      // count element <= eleMid in each row
      long long int cnt = 1;
      for (auto& row : mat) {
        auto eleLimit = eleMid + *row.begin();
        auto search = upper_bound(row.begin(), row.end(), eleLimit);
        int n       = std::max(1l, distance(row.begin(), search));
        cnt *= n;
      }
      printf("eleL=%4i, eleR=%4i, eleMid<=%4i, cnt=%4lli\n", eleL, eleR, eleMid,
             cnt);
      if (cnt < 2 * k) { // cheat, search more
        eleL = eleMid;
      } else {
        eleR = eleMid;
      }
    }
    eleMid = eleR;

    // save sum with elements <= eleMid
    vector<int> sum(1);
    int r = 1;
    for(auto& row : mat) {
      ptr itBegin = row.begin(), itEnd = row.end();
      ptr it = itBegin;
      // sum + [itBegin, it)
      vector<int> newSum;
      newSum.reserve(maxN);
      auto eleLimit = eleMid + *itBegin;
      do {
        for (auto e : sum) {
          newSum.push_back(e + *it);
        }
        ++it;
      } while (it != itEnd && *it <= eleLimit);
      sum = newSum;
      sort(sum.begin(), sum.end());
#ifdef PrintElement
      printf("row = %i, k = %i, ele <= %i, size = %li, sum = ", r, k, eleMid, sum.size());
      for (auto e : sum) { 
        cout << e << ", " ;
      }
      cout << endl;
#endif
      ++r;
    }

#ifdef PrintElement
    sort(sum.begin(), sum.end());
    printf("k = %i, ele <= %i, size = %li, sum = ", k, eleMid, sum.size());
    for (auto e : sum) { 
        cout << e << ", " ;
    }
    cout << endl;
#endif

    ptr kth = sum.begin() + k - 1;
    std::nth_element(sum.begin(), kth, sum.end());
    return *kth;
  }

  // this is wrong
  // do not filter the absolute value limit, but the limit relative the first element in a row
  int kthSmallestAbsEleMid(vector<vector<int> >& mat, int k)
  {
    const int maxN = 40;
    // element left/right value
    int eleL = 1, eleR = 1, eleMid = 0;
    for (auto& row : mat) {
      int m = row.back();
      eleR  = m > eleR ? m : eleR;
    }
    typedef vector<int>::iterator ptr;

    while (eleL + 1 < eleR) {
      eleMid = (eleL + eleR) / 2;
      // count element <= eleMid in each row
      long long int cnt = 1;
      for (auto& row : mat) {
        auto eleLimit = max(eleMid, *row.begin());
        auto search = upper_bound(row.begin(), row.end(), eleLimit);
        int n       = std::max(1l, distance(row.begin(), search));
        cnt *= n;
      }
      printf("eleL=%4i, eleR=%4i, eleMid<=%4i, cnt=%4lli\n", eleL, eleR, eleMid,
             cnt);
      if (cnt < k) {
        eleL = eleMid;
      } else {
        eleR = eleMid;
      }
    }
    eleMid = eleR;

    // save sum with elements <= eleMid
    vector<int> sum(1);
    for(auto& row : mat) {
      ptr itBegin = row.begin(), itEnd = row.end();
      ptr it = itBegin;
      // sum + [itBegin, it)
      vector<int> newSum;
      newSum.reserve(maxN);
      auto eleLimit = max(eleMid, *itBegin);
      do {
        for (auto e : sum) {
          newSum.push_back(e + *it);
        }
        ++it;
      } while (it != itEnd && *it <= eleLimit);
      sum = move(newSum);
#ifdef PrintElement
      printf("k = %i, ele <= %i, size = %li, sum = ", k, eleMid, sum.size());
      for (auto e : sum) { 
        cout << e << ", " ;
      }
      cout << endl;
#endif
    }

#ifdef PrintElement
    sort(sum.begin(), sum.end());
    sum.resize(k);
    printf("k = %i, ele <= %i, size = %li, sum = ", k, eleMid, sum.size());
    for (auto e : sum) { 
        cout << e << ", " ;
    }
    cout << endl;
#endif

    ptr kth = sum.begin() + k - 1;
    std::nth_element(sum.begin(), kth, sum.end());
    return *kth;
  }
  int kthSmallestForce(vector<vector<int>>& mat, int k)
  {
    vector<int> a = {0};
    int r = 1;
    for (auto& row : mat) {
      vector<int> b;
      for (int x : a)
        for (int y : row) b.push_back(x + y);
      sort(b.begin(), b.end());

#ifdef PrintElement
      cout << "row: " << r << endl;
      vector<int>& sum = b;
      for (auto e : sum) { 
        cout << e << ", " ;
      }
      cout << endl;
#endif

      ++r;
      if (b.size() > k)  // 保留最小的 k 个
        b.resize(k);
      a = move(b);
    }
    return a.back();
  }
};
