// https://leetcode.com/problems/counting-bits/
// 338. Counting Bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int start = 0;
        int power = 2;

        for(int i=1;i<=n;i++,start++)
        {
            if(i>=power)
            {
                power *= 2;
                start = 0;
            }
            ans[i] = 1 + ans[start];
        }  
        return ans;
    }
};
