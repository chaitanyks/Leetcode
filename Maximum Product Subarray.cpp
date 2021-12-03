class Solution {
public:
    int mxP(int l, int r, vector<int> &nums) {
        int ans = 1;
        int maxAns = INT_MIN;

        //left
        for (int i = l; i <= r; i++) {
            ans = ans * nums[i];
            if (ans > maxAns)
                maxAns = ans;

            if (ans == 0)
                ans = 1;
        }
        ans = 1;
        //right
        for (int i = r; i >= l; i--) {
            ans = ans * nums[i];
            if (ans > maxAns)
                maxAns = ans;

            if (ans == 0)
                ans = 1;
        }

        return maxAns;
    }

    int maxProduct(vector<int> &nums) {
        int ans = 1;
        int maxAns = INT_MIN;
        vector<pair<int, int>> pr;
        int l = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                pr.push_back({l, i});
                l = i + 1;
                continue;
            }
            if (i == nums.size() - 1) {
                pr.push_back({l, i});
            }
        }

        for (int i = 0; i < pr.size(); i++) {
            // cout<<pr[i].first<<" "<<pr[i].second<<endl;
            ans = mxP(pr[i].first, pr[i].second, nums);
            if (ans > maxAns)
                maxAns = ans;
        }
        return maxAns;
    }
};
