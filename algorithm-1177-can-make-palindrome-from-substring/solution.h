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
  vector<bool> canMakePaliQueries(string s, vector<vector<int> >& queries)
  {
    vector<unsigned long> prefixOddChar;
    prefixOddChar.push_back(0);

    bitset<26> oddChar;
    for (auto c : s) {
      oddChar.flip(c - 'a');
      prefixOddChar.push_back(oddChar.to_ulong());
    }

    vector<bool> answer(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      auto& q = queries[i];
      bitset<26> odd(prefixOddChar[q[0]] ^ prefixOddChar[q[1] + 1]);
      answer[i] = odd.count() <= (q[1] - q[0] + 1) % 2 + 2 * q[2];
    }
    return answer;
  }
};
