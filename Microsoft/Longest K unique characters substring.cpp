class Solution {
public:
    int longestKSubstr(string s, int k) {
        // your code here
        int n = s.length();
        vector<int> mp(26, 0);
        int ans = -1;
        int unique = 0;
        int low = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a']++;
            if (mp[s[i] - 'a'] == 1) {
                unique++;
            }

            if (unique == k) {
                if (ans < (i - low + 1))
                    ans = i - low + 1;
            }

            if (unique > k) {
                while (unique != k && low < i) {
                    mp[s[low] - 'a']--;
                    if (mp[s[low] - 'a'] == 0) {
                        unique--;
                    }
                    low++;
                }
            }

        }
        return ans;
    }
};
