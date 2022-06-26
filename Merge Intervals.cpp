class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ans;

        int start = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; i++) {
            if (intervals[start][1] >= intervals[i][0]) {
                intervals[start][1] = max(intervals[start][1], intervals[i][1]);
            } else {
                ans.push_back({intervals[start][0], intervals[start][1]});
                start = i;
            }
        }
        ans.push_back({intervals[start][0], intervals[start][1]});

        return ans;
    }
};
