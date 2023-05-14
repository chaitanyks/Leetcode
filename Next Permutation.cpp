// https://leetcode.com/problems/next-permutation/
// 31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        if(n==1)
            return ;
        
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                // cout<<i<<" ";
                index = i;
                break;
            }
        }
        
        if(index == -1)
            sort(nums.begin(),nums.end());
        
        else{
            for(int i=n-1;i>=index;i--)
            {
                if(nums[i]>nums[index])
                {
                    int val = nums[index];
                    // int val1 = nums[i];
                    
                    // for(int j = index;j<i;j++){
                    //     nums[j+1] = nums[j];
                    // }
                    
                    // nums[i] = nums[index];
                    nums[index] = nums[i];
                    nums[i] = val;
                    // cout<<i<<" "<<index<<endl;
                    
                    sort(nums.begin()+index+1,nums.end());
                    break;                  
                }
            } 
        }
    }
};
