class Solution {
public:
    int maxProfitDP(vector<int> &prices) {
        int n = prices.size();
        long long dp[100003][4];
        dp[0][1] = INT_MIN;
        dp[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            // 1 
            if (i != n)
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i - 1]);
            if (i != 1)
                dp[i][2] = max(prices[i - 1] + dp[i - 1][1], dp[i - 1][2]);

        }
        return dp[n][2];
    }

    int maxProfit(vector<int> &prices) {
        return maxProfitDP(prices);
    }
};
