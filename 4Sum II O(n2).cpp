// https://leetcode.com/problems/4sum-ii/
// 454. 4Sum II

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int n = nums1.size();

        int ans = 0;
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums3[i] + nums4[j];
                mp[sum]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums1[i] + nums2[j];
                sum = -sum;
                ans = ans + mp[sum];
            }
        }

        return ans;
    }
};
