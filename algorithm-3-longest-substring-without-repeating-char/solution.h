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
#include <stdexcept>
#include <cassert>

using namespace std;

class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    /*
    * 思路: 
    * 利用双指针 start/end，指向子字符串的首尾两端
    * 初始时: start = end = 0
    *
    * loop while ( end < size() and start + maxlen < size )
    *       待处理字符记为ch = s[end];
    *       查找当前子字符串中是否包含待处理字符ch
    *       如果包含：
    *           记录下ch 在 [start, end) 中出现的位置，记为 previous
    *           将start 设为 previous + 1
    *       如果没有包含：
    *           更新 maxlen 为 maxlen 和 end - start + 1 中的max值
    *
    *       不管ch是否出现在子串中，都将end指针往右移动一位
    *  循环结束后，maxlen 就是最长的子串长度
    */

    size_t start = 0;
    size_t maxlen = 0;
    size_t end = 0;
    size_t size = s.size();
    const char * str = s.c_str();
    while (start + maxlen < size and end < size) {
      // check if current char is duplicate with previous chars
      bool duplicate = false;
      for (size_t previous = start; previous < end; ++previous) {
        if (*(str + end) == *(str + previous)) {
          duplicate = true;
          start = previous + 1;
          break;
        }
      }
      if (!duplicate) {
        maxlen = std::max(maxlen, end - start + 1);
      }
      // move the end pointer, no matter duplicate no not
      ++end;
    }
    return maxlen;
  }

  int lengthOfLongestSubstringHashMap(string s)
  {
    const int size = s.size();
    unordered_map<char, int> charMap;
    charMap.reserve(size);

    int maxlen = 0;
    int start = 0;
    int end = 0;

    while (end < size and start + maxlen < size) {
      char ch = s.at(end);
      // use hashmap<char, index> to speed up checking duplicate
      if (charMap.count(ch) and charMap[ch] >= start) {  // duplicate with current substr
        int prev = charMap[ch];
        start = prev + 1;
      } else {
        maxlen = std::max(maxlen, end - start + 1);
      }
      charMap[ch] = end;
      ++end;
    }
    return maxlen;
  }
};

