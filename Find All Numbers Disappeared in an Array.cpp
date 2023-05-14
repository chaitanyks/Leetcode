class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        // map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] >= 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }

        vector<int> fans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                fans.push_back(i + 1);
        }
        return fans;
    }
};
