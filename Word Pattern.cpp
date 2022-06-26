// https://leetcode.com/problems/word-pattern/
// 290. Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, char> mp2;
        int n = pattern.length();
        int m = s.length();
        int in = 0;
        int i = 0;
        bool ans = true;
        for (; i < n && in < m; i++) {
            string str = "";
            char ch = pattern[i];

            while (in < m && s[in] != ' ') {
                str += s[in];
                in++;
            }
            in++;

            if (mp.find(ch) == mp.end() && mp2.find(str) == mp2.end()) {
                mp[ch] = str;
                mp2[str] = ch;
                // cout<<mp[ch]<<" "<<str<<endl;
            } else {
                // cout<<mp[ch]<<" "<<str<<endl;
                if (mp[ch] == str && mp2[str] == ch) {
                    continue;
                } else {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) {
            if (i != n)
                ans = false;
            if (in != m + 1)
                ans = false;
        }
        // cout<<n<<" "<<m<<endl;
        return ans;
    }
};
