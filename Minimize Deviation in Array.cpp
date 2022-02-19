// https://leetcode.com/problems/minimize-deviation-in-array/
// 1675. Minimize Deviation in Array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        
        int maxV,minV,ans;
        minV = ans = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2)
                nums[i] = nums[i]*2;
            pq.push(nums[i]);
            minV = min(minV,nums[i]);
        }
        
        bool find = true;
        while(find)
        {
            maxV = pq.top();
            pq.pop();
            ans = min(ans,abs(maxV-minV));
            
            if(maxV%2)
                break;
            
            minV = min(minV,maxV/2);
            pq.push(maxV/2);    
        }
        return ans;
    }
};
