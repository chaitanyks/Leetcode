// https://leetcode.com/problems/where-will-the-ball-fall/
// 1706. Where Will the Ball Fall

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        // last row
        for(int i=0;i<n;i++)
        {            
            if(grid[m-1][i] == 1 && i+1<n &&  grid[m-1][i+1]==1)
                    dp[m-1][i] = i+1;
            
            if(grid[m-1][i]==-1 && i-1>=0 && grid[m-1][i-1]==-1)
                    dp[m-1][i] = i-1;
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1 && j+1<n &&  grid[i][j+1]==1)
                    dp[i][j] = dp[i+1][j+1];
            
                else if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1)
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        
        return dp[0];
    }
};
