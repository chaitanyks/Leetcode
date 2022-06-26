class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        int n = arr.size();
        int min = INT_MAX;

        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            int val = abs(arr[i] - arr[i - 1]);
            if (min > val)
                min = val;
        }

        vector<vector<int>> ans;

        for (int i = 1; i < n; i++) {
            int val = abs(arr[i] - arr[i - 1]);
            if (min == val)
                ans.push_back({arr[i - 1], arr[i]});
        }

        return ans;
    }
};
