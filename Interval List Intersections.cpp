class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> ans;
        int i1 = 0;
        int i2 = 0;
        while (i1 != firstList.size() && i2 != secondList.size()) {
            int start = max(firstList[i1][0], secondList[i2][0]);
            int end = min(firstList[i1][1], secondList[i2][1]);

            if (start <= end) {
                ans.push_back({start, end});
            }

            firstList[i1][1] <= secondList[i2][1] ? i1++ : i2++;
        }

        return ans;
    }
};
