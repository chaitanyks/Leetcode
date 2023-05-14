// https://leetcode.com/problems/car-pooling/
// 1094. Car Pooling

class Solution {
public:
    
    bool static check(vector<int> &a,vector<int> &b)
    {
        // return abs(a) > abs(b);
        
        if(abs(a[0])==abs(b[0]) && a[0]!=b[0])
            return a[0]<b[0];
        
        return abs(a[0]) < abs(b[0]);
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        vector<vector<int>> arr;
        
        for(int i =0;i<n;i++)
        {
            int num = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            
            arr.push_back({from,num});
            arr.push_back({-to,-num});
        }
        
        sort(arr.begin(),arr.end(),check);
        
        // for(int i=0;i<2*n;i++)
            // cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        
        int maxC = 0;
        for(int i=0;i<2*n;i++)
        {
            maxC = maxC+arr[i][1];
            if(maxC>capacity)
                return false;
        }
        
        return true;
    }
};
