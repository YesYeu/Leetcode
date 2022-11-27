#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int16_t valuebuf = 20000;
        int16_t index = 0;
        for (auto i : nums)
        {
            if (i != valuebuf)
            {
                nums[index++] = i;
                valuebuf = i;
            }
        }
        return (int16_t)index;
    }
};