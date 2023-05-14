// https://leetcode.com/problems/top-k-frequent-elements/
// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        vector<int> ans;
        
        for(int i:nums)
            mp[i]++;
                
        for(auto i:mp)
            pq.push({i.second,i.first});
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
