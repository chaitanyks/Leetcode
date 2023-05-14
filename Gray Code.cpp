// https://leetcode.com/problems/gray-code/
// 89. Gray Code

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int digit = pow(2, n);
        for (int i = 0; i < digit; i++) {
            ans.push_back(i ^ (i / 2));
        }
        return ans;
    }
};
