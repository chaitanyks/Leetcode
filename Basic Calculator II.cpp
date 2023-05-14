// https://leetcode.com/problems/basic-calculator-ii/
// 227. Basic Calculator II

class Solution {
public:
    int calculate(string s) {

        stack<int> value;

        int n = s.length();
        char sign = '+';
        int val1 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int digit = s[i] - '0';
                val1 = val1 * 10 + digit;
            }

            if (s[i] != ' ' && s[i] >= '*' && s[i] <= '/' || i == n - 1) {
                if (sign == '-') {
                    val1 = -val1;
                } else if (sign == '*') {
                    val1 = value.top() * val1;
                    value.pop();
                } else if (sign == '/') {
                    val1 = value.top() / val1;
                    value.pop();
                }
                
                value.push(val1);
                val1 = 0;
                sign = s[i];
            }
        }

        int ans = 0;
        while (!value.empty()) {
            cout << value.top() << " ";
            ans = ans + value.top();
            value.pop();
        }
        return ans;
    }
};
