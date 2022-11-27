#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        typedef vector<int>::size_type int_vec;
        int_vec numofvalue = nums.size();
        int sum = 0;
        vector<int> sumResult(numofvalue);
        for(int_vec i = 0; i < numofvalue; i++)
        {
            sum += nums[i];
            sumResult[i] = sum;
        }
        return sumResult;
    }
};