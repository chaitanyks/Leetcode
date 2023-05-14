// https://leetcode.com/problems/find-the-town-judge/
// 997. Find the Town Judge

class Solution {
    public:

    int findJudge(int n, vector<vector<int>>&trust) {
        int sz = trust.size();
        map<pair<int, int>, bool> mp;
        for (int i = 0; i < sz; i++) {
            int u = trust[i][0];
            int v = trust[i][1];
            mp[{u,v}] = true;   
        }

        int townJ = 1;

        for (int i = 2; i <= n; i++) {
            if (mp[{townJ, i}]) {
                townJ = i;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i == townJ)
                continue;

            if (mp[{townJ, i}] || !mp[{i, townJ}]) {
                townJ = -1;
                break;
            }
        }

        return townJ;
    }
};
