class Solution {
public:
    bool check(vector<int> &nums, int sum, int i) {
        if (i >= nums.size())
            return false;

        if (sum < 0)
            return false;

        if (sum == 0)
            return true;

        return check(nums, sum - nums[i], i + 1) || check(nums, sum, i + 1);
    }

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i:nums)
            sum += i;

        if (sum % 2 != 0)
            return false;
        else {
            return check(nums, sum / 2, 0);
        }
    }
};
