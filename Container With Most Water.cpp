// https://leetcode.com/problems/container-with-most-water/
// 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>&height) {
        int n = height.size();
        int ans = 0;
        int low = 0;
        int high = n - 1;
        while (low < high) {
            ans = max(ans, min(height[low], height[high]) * (high - low));
            if (height[low] > height[high]) {
                high--;
            } else
                low++;
        }

        return ans;
    }
};
