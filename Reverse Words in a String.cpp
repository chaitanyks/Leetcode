
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (word.size() == 0) {
                    continue;
                }
                if (ans == "")
                    ans = word + ans;
                else
                    ans = word + " " + ans;
                word = "";
            } else {
                word = word + s[i];
            }
        }

        if (word.size() != 0) {
            if (ans == "")
                ans = word + ans;
            else
                ans = word + " " + ans;
        }

        return ans;
    }
};
