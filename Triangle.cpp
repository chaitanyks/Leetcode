// https://leetcode.com/problems/triangle/submissions/
// 120. Triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};
