// https://leetcode.com/problems/burst-balloons/
// 312. Burst Balloons

class Solution {
public:

    int solve(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // diagonal traversal

        // 00 11 22 33 44
        // 01 12 23 34
        // 02 13 24
        // 03 14 
        // 04

        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = n - i; j > 0; j--) {
                int y = n - j;
                if (x == y) {
                    if (x == 0)
                        dp[x][y] = nums[x] * nums[x + 1];
                    else if (x == n - 1)
                        dp[x][y] = nums[x] * nums[x - 1];
                    else
                        dp[x][y] = nums[x - 1] * nums[x] * nums[x + 1];
                } else {
                    for (int k = x; k <= y; k++) {
                        int val;

                        // sum left, right, extra
                        if (k != x) {
                            val = dp[x][k - 1] + dp[k + 1][y];
                        } else if (k != y)
                            val = dp[k + 1][y];
                        else
                            val = dp[x][k - 1];
                        // int val = dp[x][k-1] + dp[k+1][y];
                        int ex = nums[k];
                        if (x != 0)
                            ex = ex * nums[x - 1];
                        if (y != n - 1)
                            ex = ex * nums[y + 1];
                        val += ex;
                        dp[x][y] = max(dp[x][y], val);
                    }
                }
                x++;
            }
            // cout<<"--"<<endl;
        }
        return dp[0][n - 1];
    }

    int maxCoins(vector<int> &nums) {
        return solve(nums);
    }
};
