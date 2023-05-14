// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// 462. Minimum Moves to Equal Array Elements II

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff=0,n = nums.size();
        int mid = n/2;
        for(int i=0;i<n;i++)
        {
            diff += abs(nums[mid] - nums[i]);          
        }
        return diff;
    }
};
