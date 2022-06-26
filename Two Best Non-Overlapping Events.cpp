class Solution {
public:

    bool static custom(vector<int> &itr1, vector<int> &itr2) {

        if (itr1[1] < itr2[1])
            return true;
        else
            return false;
    }

    int bs(vector<vector<int>> &events, int low, int high, int start) {
        if (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][1] < start) {
                int val = bs(events, mid + 1, high, start);
                if (val != -1)
                    return val;
                else
                    return mid;
            } else {
                return bs(events, low, mid - 1, start);
            }
        }
        return -1;
    }

    int maxTwoEvents(vector<vector<int>> &events) {
        int n = events.size();
        sort(events.begin(), events.end(), custom);
        // int maxV[100005]={0};
        vector<int> maxV(n, 0);
        maxV[0] = events[0][2];
        for (int i = 1; i < n; i++) {
            maxV[i] = max(events[i][2], maxV[i - 1]);
            // cout<<maxV[i]<<" ";
        }

        int ans = events[0][2];

        for (int i = 1; i < n; i++) {
            ans = max(ans, events[i][2]);
            int val = bs(events, 0, i - 1, events[i][0]);
            // cout<<i<<" "<<val<<endl;
            if (val != -1)
                ans = max(ans, events[i][2] + maxV[val]);
        }

        return ans;
    }
};
