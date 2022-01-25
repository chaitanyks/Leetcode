// https://leetcode.com/problems/detect-capital/
// 520. Detect Capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        char c = word[0];

        if (c >= 'a' && c <= 'z') {
            for (int i = 0; i < n; i++) {
                c = word[i];
                if (c >= 'A' && c <= 'Z')
                    return false;
            }
        } else {
            int counta = 0;
            int countA = 0;
            for (int i = 1; i < n; i++) {
                c = word[i];
                // all small
                if (c >= 'a' && c <= 'z')
                    counta++;
                if (c >= 'A' && c <= 'Z')
                    countA++;
            }

            if (counta != 0 && countA != 0)
                return false;
        }
        return true;
    }
};