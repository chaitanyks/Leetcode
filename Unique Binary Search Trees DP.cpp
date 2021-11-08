class Solution {
public:
    vector<long long> dp;

    Solution() {
        dp.assign(20, 0);
        dp[1] = 1;
        for (int i = 1; i < 19; i++) {
            dp[i + 1] = (2 * ((2 * i) + 1) * dp[i]) / (i + 2);
        }
    }

    int numTrees(int n) {
        return dp[n];
    }
};
