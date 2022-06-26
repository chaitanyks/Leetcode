// https://leetcode.com/problems/add-digits/
// 258. Add Digits

class Solution {
public:
    int addDigits(int num) {
        int ans = num;
        while(ans>=10)
        {
            int temp = 0;
            while(ans!=0)
            {
                temp += ans%10;
                ans = ans/10;
            }
            ans = temp;
        }
        
        return ans;
    }
};