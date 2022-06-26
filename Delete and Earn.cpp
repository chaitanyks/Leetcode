// https://leetcode.com/problems/delete-and-earn/
// 740. Delete and Earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        
        int mx = 0;
        for(int i: nums) {
            mp[i] += i;
            mx = max(mx,i);
        }
        
        vector<vector<int>> dp(mx+1,vector<int>(2,0));
        
        for(int i=1;i<=mx;i++)
        {
            dp[i][0] = max(dp[i-1][0],mp[i] + dp[i-1][1]);
            dp[i][1] = dp[i-1][0];
        }
        
        return max(dp[mx][0],dp[mx][1]);
    }
};
