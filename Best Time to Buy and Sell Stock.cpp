// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int stocks = prices[0];
        int n = prices.size();
        
        for(int i=0;i<n;i++)
        {
            if(prices[i]<stocks)
                stocks = prices[i];
            ans = max(ans,prices[i] - stocks);
        }
        return ans;
    }
};
