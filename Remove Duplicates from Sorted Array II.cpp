// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int count = 1;
        int n = nums.size();
        int pos = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
            {
                if(count == 1)
                {
                    nums[pos] = nums[i];
                    pos++;
                    count++;
                    k++;
                }
            }
            else
            {
                nums[pos] = nums[i];
                pos++;
                count = 1;
                k++;
            }
        }
        
        return k;
    }
};