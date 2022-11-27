#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        int sumofWealth = 0;
        for(auto acct : accounts)
        {
            if((sumofWealth = accumulate(acct.begin(), acct.end(),0)) > maxWealth)
                maxWealth = sumofWealth;
        }
        return maxWealth;
    }
};