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
  struct Record
  {
    char ch;
    int len;
    int cntOther;
    Record(char c) : ch(c)
    {
      len = 1;
      cntOther = 0;
    }
    void add(char c)
    {
      if (c != ch) ++cntOther;
      if (cntOther > tolerance) return;
      ++len;
    }
    bool expired() const { return cntOther > tolerance; }
    void print() const { printf("\tch=%c, len=%i, cntOther=%i, expired=%i\n", ch, len, cntOther, expired()); }
  };

  // limite rec, remove expired records
  int maxRepOpt1(string text)
  {
#ifdef DebugPrint
    cout << "text: " << text << endl;
#endif
    std::unordered_map<char, int> cnt;
    for (auto& c : text) ++cnt[c];

    std::vector<Record> rec;
    int maxRpt = 0;
    char last = '\0';
#ifdef DebugPrint
    int idx = 0;
#endif
    for (auto& c : text) {
      for (auto it = rec.begin(); it != rec.end();) {
        it->add(c);
        if (it->expired()) {
          maxRpt = max(maxRpt, min(cnt[it->ch], it->len));
          it = rec.erase(it);
        } else {
          ++it;
        }
      }
      if (c != last) rec.emplace_back(c);
      last = c;

#ifdef DebugPrint
      for (int i = 0; i < rec.size(); ++i) {
        printf("index=%i, char=%c, maxRpt=%i, record=%i", idx, c, maxRpt, i);
        rec[i].print();
      }
      ++idx;
#endif
    }
    // not expired records, result = len + 1 - cntOther
    for (auto& r : rec) {
      maxRpt = max(maxRpt, min(cnt[r.ch], r.len + 1 - r.cntOther));
    }
    return maxRpt;
  }
 private:
  const static int tolerance = 1;
};
