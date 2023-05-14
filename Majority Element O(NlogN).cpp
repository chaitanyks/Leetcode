// https://leetcode.com/problems/majority-element/
// 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums[0];
        int count = 1;
        int mcount = 1;
        int n = nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] != nums[i-1])
            {
                if(mcount<count)
                {
                    mcount = count;
                    ans = nums[i-1];
                }
                count = 1;
            }
            else{
                count++;
            }
            
            if(i == n-1)
            {
                if(mcount<count)
                {
                    mcount = count;
                    ans = nums[i];
                }
            }
        }
        
        return ans;
    }
};
