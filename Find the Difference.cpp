// https://leetcode.com/problems/find-the-difference/
// 389. Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> mp (26, 0);
        int n = s.length();
        char ans;
        int index;

        for (int i = 0; i < n; i++) {
            index = s[i] - 'a';
            mp[index]++;
            index = t[i] - 'a';
            mp[index]--;
        }

        index = t[n] - 'a';
        mp[index]--;

        for (int i = 0; i < 26; i++) {
            if (mp[i] == -1) {
                ans = 'a' + i;
                break;
            }
        }

        return ans;
    }
};