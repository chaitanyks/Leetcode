class Solution {
public:

    int rec(vector<int> &nums, int index, int n) {
        if (index >= n)
            return 0;
        int ans1 = nums[index] + rec(nums, index + 2, n);
        int ans2 = rec(nums, index + 1, n);

        return max(ans1, ans2);
    }

    int rob(vector<int> &nums) {
        return rec(nums, 0, nums.size());
    }
};
