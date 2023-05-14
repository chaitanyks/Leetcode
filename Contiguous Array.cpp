// https://leetcode.com/problems/contiguous-array/
// 525. Contiguous Array

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        int ans = 0;

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                sum--;
            else
                sum++;

            if (sum == 0)
            {
                ans = max(ans, i + 1);
                continue;
            }

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
            else
                ans = max(ans, i - mp[sum]);
        }

        return ans;
    }
};