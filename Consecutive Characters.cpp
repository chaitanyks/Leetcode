class Solution {
public:
    int maxPower(string s) {

        int ans = 1;
        int count = 1;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
                ans = max(ans, count);
            } else {
                count = 1;
            }
        }
        return ans;
    }
};
