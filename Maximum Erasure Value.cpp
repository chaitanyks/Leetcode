// https://leetcode.com/problems/maximum-erasure-value/submissions/
// 1695. Maximum Erasure Value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        int start = 0;
        
        for(int i=0;i<n;i++)
        {            
            while(mp[nums[i]] != 0)
            {
                sum -= nums[start];
                mp[nums[start]]--;
                start++;
            }
            
            mp[nums[i]]++;
            sum += nums[i];
            ans = max(ans, sum);
        }
        
        return ans;        
    }
};
