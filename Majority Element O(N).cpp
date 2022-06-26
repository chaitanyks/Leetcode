// https://leetcode.com/problems/majority-element/
// 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        int ans,count = 0;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>count)
            {
                ans = nums[i];
                count = mp[nums[i]];
            }
        }
        
        return ans;
    }
};
