class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        map<int, int> mp;

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0)
                mp[count[i]]++;
        }
        mp[0] = 0;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[count[i]] == 0 || mp[count[i]] == 1)
                continue;
            else {
                mp[count[i]]--;
                // count[i]--;
                // ans++;
                while (mp[count[i]] != 0) {
                    count[i]--;
                    ans++;
                }

                //edge case
                if (count[i] != 0)
                    mp[count[i]]++;
            }
        }
        return ans;

    }
};
