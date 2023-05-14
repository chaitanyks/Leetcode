// https://leetcode.com/problems/subarray-sum-equals-k/
// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> count;
        int ans = 0;
        int sum = 0;
        count[0] = 1;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            ans += count[sum-k];
            count[sum]++;
        }
        
        return ans;
    }
};