class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int val = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == val) {
                    // ans.push_back({nums[i],nums[left],nums[right]});
                    st.insert({nums[i], nums[left], nums[right]});
                    // break;
                    left++;
                } else if (sum < val) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        auto itr = st.begin();
        for (itr = st.begin(); itr != st.end(); itr++) {
            ans.push_back(*itr);
        }
        return ans;
    }
};
