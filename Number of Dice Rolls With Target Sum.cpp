// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// 1155. Number of Dice Rolls With Target Sum

class Solution {
public:
    int M = pow(10,9) + 7;
    
    int solve(int n,int k,int target,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(target==0)
                return 1;
            else
                return 0;
        }
        
        if(target<0)
            return 0;
        
        int ans = 0;
        if(dp[n][target]==-1)
        {
            for(int i=1;i<=k;i++)
            {
                ans = (ans + solve(n-1,k,target-i,dp)%M)%M;
            }
            dp[n][target] = ans;
        }
        return dp[n][target];        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        
        for(int i=1;i<=min(target,k);i++)
        {
            dp[1][i] = 1;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int ans = 0;
                for(int v = 1; v<=k && j>=v;v++)
                {
                    ans = (ans + dp[i-1][j-v]%M)%M;
                }
                dp[i][j] = ans;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        cout<<dp[n][target]<<" "<<endl;
        // return solve(n,k,target,dp);
        return dp[n][target];
    }
};
