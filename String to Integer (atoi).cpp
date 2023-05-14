// https://leetcode.com/problems/string-to-integer-atoi/
// 8. String to Integer (atoi)

class Solution {
public:

    int myAtoi(string s) {
        int n = s.length();
        int mn = INT_MIN;
        int mx = INT_MAX;
        long long ans = 0;
        int i = 0;

        while (i < n && s[i] == ' ')
            i++;

        bool neg = false;
        if (i < n) {

            if (s[i] == '-') {
                neg = true;
                i++;
            } else if (s[i] == '+') {
                neg = false;
                i++;
            }
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int val = s[i] - '0';

            if (neg)
                ans = ans * 10 - val;
            else
                ans = ans * 10 + val;

            if (ans <= mn) {
                ans = mn;
                break;
            }

            if (ans >= mx) {
                ans = mx;
                break;
            }
            i++;
        }
        return ans;
    }
};
