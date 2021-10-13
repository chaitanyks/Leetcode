#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mp;
        vector<int> vp;
        for (int i = 0; i < nums.size(); i++) {
            int ns = target - nums[i];
            if (mp.find(ns) != mp.end()) {
                vp.push_back(mp[ns]);
                vp.push_back(i);
                break;
            } else
                mp[nums[i]] = i;
        }
        return vp;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;
    vector<int> ans = solution.twoSum(nums, target);

    for (int i:ans) {
        cout << i << " ";
    }
}