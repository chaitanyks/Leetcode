/*
create a map that store the right most index of character
run a loop and update the right most index value
*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        vector<int> mp(26, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (mp[s[i] - 'a'] == 0) {
                mp[s[i] - 'a'] = i;
            }
        }

        int i = 0;
        while (i < n) {
            int right = mp[s[i] - 'a'];
            int j = i;
            while (j <= right) {
                if (right < mp[s[j] - 'a'])
                    right = mp[s[j] - 'a'];
                j++;
            }
            ans.push_back(right - i + 1);
            i = right + 1;
        }

        return ans;
    }
};
