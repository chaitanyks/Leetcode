// https://leetcode.com/problems/maximize-distance-to-closest-person/
// 849. Maximize Distance to Closest Person

class Solution {
public:

    int maxDistToClosest(vector<int>&seats) {
        int start = 0;
        int n = seats.size();
        int dis = 0;
        for (int i = 0; i < n; i++) {
            //corner case
            if (seats[i] == 1 && start == 0 && seats[start] == 0) {
                dis = max(dis, i);
                start = i;
            } else if (seats[i] == 1) {
                dis = max(dis, (i - start) / 2);
                start = i;
            }
            //corner case
            if (seats[i] == 0 && i == n - 1) {
                dis = max(dis, (i - start));
            }
        }
        return dis;
    }
};
