class Solution {
public:
    bool bitApproach(vector<int> &nums, int sum) {
        bitset<200001> bit(1);
        for (int i:nums)
            bit = bit | bit << i;
        return bit[sum] & 1;
    }

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i:nums)
            sum += i;

        if (sum % 2 != 0)
            return false;
        else {
            return bitApproach(nums, sum / 2);
        }
    }
};
