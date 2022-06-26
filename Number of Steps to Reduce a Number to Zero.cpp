// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// 1342. Number of Steps to Reduce a Number to Zero
// a(n) = (weight of binary expansion of n) + (length of binary expansion of n) - 1.

class Solution {
public:
    int numberOfSteps(int num) {

        if(num == 0 || num == 1)
            return num;
        
        int ans = log2(num);
        while(num)
        {
            num = num & (num-1);
            ans++;
        }
        
        return ans;
    }
};
