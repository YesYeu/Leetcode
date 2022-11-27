#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int j = 0;
        while (num != 0)
        {
            j += (num > 1 ? 1 : 0) + (num & 0x01);
            num >>= 1;
        }
        return j;
    }
};