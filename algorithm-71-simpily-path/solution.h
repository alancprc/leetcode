#pragma once

#include <algorithm>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cstdio>
#include <deque>
#include <regex>

using namespace std;

class Solution
{
 public:
  string simplifyPath(string path)
  {
    // split with '/'
    vector<string> simplified;
    char delimiter = '/';
    for (size_t begin = 0, end = 0; begin != string::npos; begin = end) {
      begin = path.find_first_not_of(delimiter, begin);
      end = path.find_first_of(delimiter, begin);
      if (begin != string::npos) {
        string dir = path.substr(begin, end - begin);
        if (dir == "..") {
          if (!simplified.empty()) simplified.pop_back();
        } else if (dir == ".") {
          continue;
        } else {
          simplified.push_back(dir);
        }
      }
    }

    if (simplified.empty()) return "/";

    string result;
    for (auto &s : simplified) {
      result.append("/");
      result.append(s);
    }
    return result;
  }
};
