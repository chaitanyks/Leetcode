// https://leetcode.com/problems/remove-covered-intervals/submissions/
// 1288. Remove Covered Intervals

class Solution {
public:
    static bool custom(vector<int> &a,vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1]>b[1];
        
        return a[0]<b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end(),custom);
        
        int endT = intervals[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][1]>endT)
                ans++;
            endT = max(endT,intervals[i][1]);
        }
        
        return ans;
    }
};
