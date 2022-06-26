class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temp) {
        vector<int> ans;
        stack<pair<int, int>> st;
        int n = temp.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }

            if (st.empty()) {
                st.push({temp[i], i});
                ans.push_back(0);
            } else {
                ans.push_back(st.top().second - i);
                st.push({temp[i], i});
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
