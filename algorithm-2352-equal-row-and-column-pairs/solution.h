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
  int equalPairs(vector<vector<int>>& grid)
  {
    map<vector<int>, int> rowCnt;
    for (auto& v : grid) ++rowCnt[v];
    // for (auto& it : rowCnt) {
    //   cout << it.second << ": ";
    //   for (auto& i : it.first) cout << i << " ";
    //   cout << endl;
    // }

    const int n = grid.size();
    int cnt = 0;
    for (int col = 0; col != n; ++col) {
      vector<int> column(n);
      for (int row = 0; row != n; ++row) {
        column[row] = grid[row][col];
      }
      if (rowCnt.count(column)) cnt += rowCnt[column];
      // for (auto e : column) cout << e << " ";
      // cout << ", cnt:" << cnt << endl;
    }
    return cnt;
  }
};
