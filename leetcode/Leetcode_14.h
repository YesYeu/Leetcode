#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    for (auto i : strs)
      if (i.empty()) return "";

    int index = 0;
    while (1) {
      int flag = 1;
      for (auto i : strs)
        if (i[index] != strs[0][index] || i[index] == '\0')
          return strs[0].substr(0, index);
        else
          index++;
    }
    return strs[0].substr(0, index);
  }
};


/**
 * @brief  Divide and conqure
 * 
 */
class Solution1 {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
      return "";
    else {
      return longestCommonPrefix_Aux(strs, 0, strs.size());
    }
  }

  string longestCommonPrefix_Aux(vector<string>& strs, int start, int end) {
    if (start + 1 >= end)
      return strs[start];
    else {
      int mid = (start + end) / 2;
      string left = longestCommonPrefix_Aux(strs, start, mid);
      string right = longestCommonPrefix_Aux(strs, mid, end);
      return Comparetwostring(left, right);
    }
  }

  string Comparetwostring(const string& left, const string& right) {
    int minlength = min(left.size(), right.size());
    for (int i = 0; i < minlength; i++) {
      if (left[i] != right[i]) return left.substr(0, i);
    }
    return left.substr(0, minlength);
  }
};