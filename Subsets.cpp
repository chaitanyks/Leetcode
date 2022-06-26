// https://leetcode.com/problems/subsets/
// 78. Subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>&nums) {
        int n = nums.size();
        int powerSet = pow(2, n);

        bitset< 10 > binary;
        vector<vector<int>> ans;
        vector<int> temp;

        for (int i = 0; i < powerSet; i++) {
            temp = vector < int>();
            binary = i;

            for (int j = 0; j < n; j++) {
                if (binary[j] == 1)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
