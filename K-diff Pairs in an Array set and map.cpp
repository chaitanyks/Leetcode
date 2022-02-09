// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// 532. K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>&nums, int k) {
        int n = nums.size();
        set<pair<int, int>> st;
        map<int, int> mp;
        int ans = 0;
        int val1, val2, val3;

        for (int i = 0; i < n; i++)
            mp[nums[i]]++;

        for (int i = 0; i < n; i++) {
            val1 = nums[i];
            val2 = nums[i] - k;
            val3 = nums[i] + k;

            // base case
            if (k == 0) {
                if (mp[val1] >= 2)
                    st.insert({val1, val1});

                mp[val1] = 0;
            }

            if (mp[val2] != 0) {
                if (val1 < val2)
                    st.insert({val1, val2});
                else
                    st.insert({val2, val1});
            }

            if (mp[val3] != 0) {
                if (val1 < val3)
                    st.insert({val1, val3});
                else
                    st.insert({val3, val1});
            }
        }

        return st.size();
    }
};