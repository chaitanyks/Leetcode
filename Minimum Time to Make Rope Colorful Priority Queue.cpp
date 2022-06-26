class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {
        int n = colors.size();
        priority_queue<int> pq;
        int ans = 0;
        // int index = 0;
        pq.push(-neededTime[0]);
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1]) {
                while (pq.size() > 1) {
                    ans = ans + abs(pq.top());
                    pq.pop();
                }
                pq.pop();
                pq.push(-neededTime[i]);
            } else {
                pq.push(-neededTime[i]);
            }
        }

        // last case
        while (pq.size() > 1) {
            ans = ans + abs(pq.top());
            pq.pop();
        }

        return ans;
    }
};
