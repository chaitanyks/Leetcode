// https://leetcode.com/problems/champagne-tower/submissions/
// 799. Champagne Tower

class Solution {
public:
    vector<vector<double>> dp;
    double champagneTower(int poured, int query_row, int query_glass) {
        dp.resize(101,vector<double>(101,0));
        // query_row++;
        double ans = 0;
        
        if(poured==0)
            return 0;
        
        if(query_row==0)
            return 1.00000;
        
        dp[0][0] = (double)poured - 1;
        
        for(int i=1;i<=query_row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                    dp[i][j] = (dp[i-1][j])/2;
                else if(j==i)
                    dp[i][j] = (dp[i-1][j-1])/2;
                else
                    dp[i][j] = dp[i-1][j]/2 + dp[i-1][j-1]/2;
                
                if(dp[i][j]<=1)
                    dp[i][j] = 0;
                else
                    dp[i][j] -= 1;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        if(query_glass == 0)
            ans = dp[query_row-1][query_glass]/2;        
        else if(query_glass == query_row)
            ans = dp[query_row-1][query_glass-1]/2;
        else
            ans = dp[query_row-1][query_glass-1]/2 + dp[query_row-1][query_glass]/2;
        
        return ans>=1?1.00000:ans;        
    }
};
