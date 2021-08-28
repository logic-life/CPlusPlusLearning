#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto i = nums.begin();
        int k = 0;
        for (auto j = nums.begin() + 1; j < nums.end(); j++)
        {
            if (*i != *j)
            {
                *(i + 1) = *(j);
                i++;
            }
            else
                k++;
        }
        return nums.size() - k;
    }
    Solution() = default;
};
