// https://leetcode.com/problems/rotate-array/
// 189. Rotate Array

class Solution {
public:
    
    int gcd(int a,int b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int steps = gcd(n,k);
        
        for(int i=0;i<steps;i++)
        {
            int j = (i+k)%n;
            int val = nums[i];
            while(j!=i)
            {
                int temp = nums[j];
                nums[j] = val;
                val = temp;
                j = (j+k)%n;
            }
            nums[j] = val;
        }
    }
};
