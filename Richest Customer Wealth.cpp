// https://leetcode.com/problems/richest-customer-wealth/
// 1672. Richest Customer Wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int ans = 0;
        int wealth = 0;
        
        for(int i=0;i<n;i++)
        {
            wealth = 0;
            for(int j=0;j<m;j++)
                wealth+= accounts[i][j];
            ans = max(ans,wealth);
        }        
        return ans;
    }
};
