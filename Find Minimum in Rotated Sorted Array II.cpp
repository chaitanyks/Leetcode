class Solution {
public:
    int findMin(vector<int> &nums) {
        int minVal = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minVal)
                minVal = nums[i];
        }
        return minVal;
    }
};
