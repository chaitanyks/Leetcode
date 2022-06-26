class Solution {
public:
    int bs(vector<int> &nums, int l, int h) {
        int mid = (l + h) / 2;
        if (mid == l) {
            return min(nums[l], nums[h]);
        }
        if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
            return nums[mid];
        } else {
            return min(bs(nums, l, mid - 1), bs(nums, mid + 1, h));
        }
    }

    int findMin(vector<int> &nums) {
        return bs(nums, 0, nums.size() - 1);
    }
};
