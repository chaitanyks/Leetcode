// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// 81. Search in Rotated Sorted Array II

class Solution {
public:
    
    bool mbs(vector<int> & nums,int target,int low,int high)
    {
        while(low<=high)
        {
            int mid = (low+high)/2;
            // cout<<mid<<" ";
            if(nums[mid]==target)
                return true;
            
            // //extra case
            if(nums[mid]==nums[low] && nums[mid]==nums[high])
                return mbs(nums,target,low,mid-1) || mbs(nums,target,mid+1,high);
            
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && nums[mid]>=target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            
            else
            {
                if(nums[high]>=target && nums[mid]<=target)
                    low = mid+1;
                else
                    high = mid-1;
            }
            
        }
        
        return false;
    }
    
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return mbs(nums,target,0,n-1);
    }
};
