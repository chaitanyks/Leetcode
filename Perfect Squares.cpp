class Solution {
public:
    int numSquares(int n) {
        
        int sq = sqrt(n);
        // if(sq*sq == n)
        // {
        //     return 1;
        // }

        int dp[101][10005];
        for(int i=0;i<=sq;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<=sq;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1)
                {
                    dp[i][j] = 1+dp[i][j-i*i];
                }
                else{
                if(j<i*i)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-i*i]);
                }
                }
            }
        }
        
        // for(int i=0;i<=sq;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[sq][n];
    }
};
