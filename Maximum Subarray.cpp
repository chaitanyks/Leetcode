class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = INT_MIN;
        int sum = 0;

        for (auto val:nums) {
            sum += val;
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        
        return ans;
    }
};
