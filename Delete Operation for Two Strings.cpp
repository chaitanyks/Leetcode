// https://leetcode.com/problems/delete-operation-for-two-strings/
// 583. Delete Operation for Two Strings

class Solution {
public:
    
    int minEdit(string s1,string s2,int i,int j)
    {
        if(i>=s1.length())
            return s2.length()-j;
        
        if(j>=s2.length())
            return s1.length()-i;
        
        if(s1[i]==s2[j])
            return minEdit(s1,s2,i+1,j+1);
        
        return 1+min(minEdit(s1,s2,i+1,j),minEdit(s1,s2,i,j+1));
    }
    
    int minEditDP(string s1,string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        return minEditDP(word1,word2);
    }
};
