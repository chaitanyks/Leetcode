class Solution {
public:

    // dp solution
    bool solve(vector<int> &nums, int sum) {
        int n = nums.size();
        int m = sum;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }

        if (dp[n][sum] == 1)
            return true;
        return false;
    }

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i:nums)
            sum += i;

        if (sum % 2 != 0)
            return false;
        else {
            return solve(nums, sum / 2);
        }
    }
};
