class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {
        int n = colors.size();

        int ans = 0;
        int sum = neededTime[0];
        int maxV = neededTime[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1]) {
                if (count > 1) {
                    ans = ans + sum - maxV;
                }
                sum = neededTime[i];
                maxV = neededTime[i];
                count = 1;
            } else {
                count++;
                maxV = max(maxV, neededTime[i]);
                sum = sum + neededTime[i];
            }
        }

        // corner case last element
        if (count > 1) {
            ans = ans + sum - maxV;
        }

        return ans;
    }
};
