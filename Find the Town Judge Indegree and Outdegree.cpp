// https://leetcode.com/problems/find-the-town-judge/
// 997. Find the Town Judge

class Solution {
    public:

    int findJudge(int n, vector<vector<int>>&trust) {
        vector<int> inDegree (n + 1, 0);
        vector<int> outDegree (n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            inDegree[trust[i][1]]++;
            outDegree[trust[i][0]]++;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                ans = i;
            }
        }
        return ans;
    }
};
