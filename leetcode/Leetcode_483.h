#include <iostream>
#include <vector>
using namespace std;

typedef int occur_cnt_t;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        typedef vector<occur_cnt_t>::size_type vec_index_t;
        vector<occur_cnt_t> mag_statistic(128, 0);
        vector<occur_cnt_t> ransomNote_statistic(128, 0);

        for (auto i : magazine)
            mag_statistic[(vec_index_t)i]++;
        for (auto j : ransomNote)
            ransomNote_statistic[(vec_index_t)j]++;
        for (vec_index_t k = 0; k < 128; k++)
        {
            if (mag_statistic[k] < ransomNote_statistic[k])
                return false;
        }
        return true;
    }
};