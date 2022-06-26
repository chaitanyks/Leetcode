class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int n = points.size();
        // distance calculate
        for(int i=0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            pq.push({-dis,{x,y}});
        }
        
        // find out the nearest points
        for(int i=0;i<k;i++)
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
        }
        
        return ans;
    }
};
