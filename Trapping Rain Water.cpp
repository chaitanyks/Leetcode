class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 1 || n == 2)
            return 0;

        vector<int> left(n + 1, 0);
        vector<int> right(n + 1, 0);
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            int val = min(left[i - 1], right[i + 1]);
            int h = height[i];
            if (h < val)
                ans += (val - h);
            // cout<<ans<<" ";
        }
        return ans;
    }
};
