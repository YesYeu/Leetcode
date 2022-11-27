#include <iostream>
#include <vector>
using namespace std;


/* 二分查找 */


class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;

    int a = 0, b = nums.size();
    while (a < b - 1) {
      int c = (a + b) / 2;
      if (target == nums[c])
        return c;
      else if (target < nums[c])
        b = c;
      else
        a = c;
    }

    if (target < nums[a])
      return a;
    else 
      return a + 1;
  }
};