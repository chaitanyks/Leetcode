// https://leetcode.com/problems/smallest-integer-divisible-by-k/
// 1015. Smallest Integer Divisible by K

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int ans = -1;
        int val = 0;

        for (int i = 0; i < 214748; i++) {
            val = val * 10 + 1;
            val = val % k;
            if (val == 0) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
