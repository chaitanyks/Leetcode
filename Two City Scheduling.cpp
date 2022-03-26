// https://leetcode.com/problems/two-city-scheduling/
// 1029. Two City Scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> pq;
        int n = costs.size();
        
        for(int i=0;i<n;i++)
            pq.push({costs[i][1] - costs[i][0],i});
        
        int index = 0;
        int ans = 0;
        
        while(!pq.empty())
        {
            int i = pq.top().second;
            pq.pop();
            // cout<<costs[i][0]<<" ";
            
            if(index<n/2)
                ans += costs[i][0];
            else
                ans += costs[i][1];
            
            index++;
        }
        
        return ans;
    }
};
