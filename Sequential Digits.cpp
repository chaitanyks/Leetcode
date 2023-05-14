// https://leetcode.com/problems/sequential-digits/submissions/
// 1291. Sequential Digits

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        vector<int> digit;

        for (int i = 0; i <= 9; i++)
            digit.push_back(i);
        
        int val;
        
        for (int len = 2; len <= 9; len++) {
            
            for (int d = 0; d < digit.size() - len; d++) {
                val = 0;
                for (int i = 1; i <= len; i++) {
                    val = val * 10 + digit[d + i];
                }
                // cout<<val<<" ";
                if (val >= low && val <= high)
                    ans.push_back(val);
            }
        }
        return ans;
    }
};
