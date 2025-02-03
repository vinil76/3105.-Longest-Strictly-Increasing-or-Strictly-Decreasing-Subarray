#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int MaxInc = 1, MaxDec = 1;
    int incCount = 1, decCount = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            incCount++;
            decCount = 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            decCount++;
            incCount = 1;
        }
        else
        {
            incCount = 1;
            decCount = 1;
        }
        MaxInc = max(incCount, MaxInc);
        MaxDec = max(decCount, MaxDec);
    }
    return max(MaxDec, MaxInc);
}
int main()
{
    vector<int> nums = {1, 2, 2, 1};
    cout << longestMonotonicSubarray(nums);

    return 0;
}