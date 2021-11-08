class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        int n = s.length();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        vector<int> lc(n, 0);

        if (s[0] == '|')
            left[0] = 0;

        if (s[n - 1] == '|')
            right[n - 1] = n - 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '|') {
                left[i] = i;
                lc[i] = 1 + lc[i - 1];
            } else {
                left[i] = left[i - 1];
                lc[i] = lc[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '|')
                right[i] = i;
            else
                right[i] = right[i + 1];
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int l = right[queries[i][0]];
            int r = left[queries[i][1]];
            if (l <= r && l != -1 && r != -1) {
                int len = r - l + 1;
                int diff = lc[r] - lc[l] - 1;
                ans.push_back(len - diff - 2);
                // cout<<l<<" "<<r<<" "<<len<<" "<<diff<<" "<<len-diff-2<<endl;
            } else
                ans.push_back(0);
        }
        return ans;
    }
};
