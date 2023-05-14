// https://leetcode.com/problems/jump-game-vi/
// 1696. Jump Game VI

class Solution {
public:    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1],n-1});
        
        for(int i = n-2;i>=0;i--)
        {
            while(pq.top().second>i+k)
                pq.pop();
                  
            pq.push({nums[i] + pq.top().first,i});
        }
        
        while(pq.top().second!=0)
            pq.pop();
        
        return pq.top().first;     

    }
};
