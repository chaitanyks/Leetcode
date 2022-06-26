// https://leetcode.com/problems/palindrome-partitioning/
// 131. Palindrome Partitioning

class Solution {
public:
    vector<vector<string>> fans;

    vector<vector<bool>> allPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp (n, vector < bool > (n, false));

        for (int k = n - 1; k >= 0; k--) {
            for (int i = 0; i <= k; i++) {
                int j = n - 1 - k + i;

                if (i == j) {
                    dp[i][j] = true;
                    continue;
                }
                if (s[i] == s[j] && j - i != 1) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (s[i] == s[j] && j - i == 1) {
                    dp[i][j] = true;
                }
            }
        }
        return dp;
    }

    void print(string s, vector<vector<bool>> &dp, int i, vector<string> &temp) {
        int n = s.length();
        string sub;
      
        if (i == n) {
            // cout<<"i";
            fans.push_back(temp);
            return;
        }
        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                sub = s.substr(i, j - i + 1);
                // cout<<sub<<" ";
                temp.push_back(sub);
                print(s, dp, j + 1, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp;
        vector<string> temp;
        dp = allPalindrome(s);
        print(s, dp, 0, temp);
        return fans;
    }
};
