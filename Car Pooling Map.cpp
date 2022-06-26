// https://leetcode.com/problems/car-pooling/
// 1094. Car Pooling

class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        map<int,int> mp;
        
        for(int i =0;i<n;i++)
        {
            int num = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            
            mp[from]+=num;
            mp[to]-=num;
        }
        
        int maxC = 0;
        for(auto itr = mp.begin();itr!=mp.end();itr++)
        {
            // cout<<itr->first<<" "<<itr->second<<endl;
            maxC+=itr->second;
            if(maxC>capacity)
                return false;
        }
        return true;
    }
};
