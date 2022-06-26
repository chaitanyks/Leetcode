// https://leetcode.com/problems/summary-ranges/
// 228. Summary Ranges

class Solution {
public:
    void range(int start,int end,vector<string> &ans) {
        
        if(start == end)
            ans.push_back(to_string(end));
        else 
            ans.push_back(to_string(start) + "->" + to_string(end));
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        
        //corner case
        if(n==0)
            return ans;
        
        int start = nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i-1] + 1 != nums[i]) {
                range(start,nums[i-1],ans);     
                start = nums[i];
            }
        }
        
        //last index case
        range(start,nums[n-1],ans);
        return ans;
    }
};
