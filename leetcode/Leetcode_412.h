#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> answer(n, "");
        for (int i = 1; i < n + 1; i++)
        {
            bool flag = 0;
            if (i % 3 == 0 && i >= 3)
            {
                flag = 1;
                answer[i - 1] += string("Fizz");
            }
            if (i % 5 == 0 && i >= 5)
            {
                flag = 1;
                answer[i - 1] += string("Buzz");
            }
            if (flag == 0)
            {
                char buf[6] = {'\0'};
                sprintf(buf, "%d", i);
                answer[i - 1] = string((const char *)buf);
            }
        }
        return answer;
    }
};