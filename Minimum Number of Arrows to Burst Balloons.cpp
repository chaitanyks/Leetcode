// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// 452. Minimum Number of Arrows to Burst Balloons

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>&points) {
        int n = points.size();
        int ans = 1;

        sort(points.begin(), points.end());
        int end = points[0][1];

        for (int i = 0; i < n; i++) {
            if (points[i][0] <= end) {
                end = min(end, points[i][1]);
            } else {
                ans++;
                end = points[i][1];
            }
        }
        return ans;
    }
};
