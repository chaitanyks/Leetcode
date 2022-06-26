class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<long long> left(n + 1);
        vector<long long> right(n + 1);

        left[0] = 1;
        right[n - 1] = 1;
        for (int i = 1; i <= n; i++) {
            left[i] = nums[i - 1] * left[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        int count0 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count0++;
        }

        if (count0 >= 2) {
            vector<int> temp(n, 0);
            return temp;
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(left[i] * right[i]);
        }

        return ans;
    }
};
