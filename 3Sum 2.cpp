class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {

        vector<vector<int>> ans;
        if (nums.size() <= 2)
            return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int val = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            if (i == 0 || nums[i] != nums[i - 1]) {
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == val) {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        // st.insert({nums[i],nums[left],nums[right]});
                        // break;
                        // left++;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    } else if (sum < val) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
