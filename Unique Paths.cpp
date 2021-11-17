class Solution {
public:
    // vector<vector<int>> dp(101,vector<int>(101));
    unsigned dp[100][100];

    Solution() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
    }

    int uniquePaths(int m, int n) {
        unsigned dp[100][100];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
