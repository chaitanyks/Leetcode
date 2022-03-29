// https://leetcode.com/problems/find-the-duplicate-number/
// 287. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])]>0)
                nums[abs(nums[i])] = -1 * nums[abs(nums[i])];
            else
                return abs(nums[i]);
        }
        return 0;
    }
};
