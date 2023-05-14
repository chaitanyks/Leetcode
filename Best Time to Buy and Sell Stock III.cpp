class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

		int s1 = -prices[0], s2 = 0, s3 = INT_MIN, s4 = 0;

		for (int i = 1; i < prices.size(); i++) {
			s1 = max(s1, -prices[i]);
			s2 = max(s2, s1 + prices[i]);
			s3 = max(s3, s2 - prices[i]);
			s4 = max(s4, s3 + prices[i]);
		}

		return s4;
    }
};
