// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int M = pow(10, 9) + 7;

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        verticalCuts.push_back(w);
        verticalCuts.insert(verticalCuts.begin(), 0);

        horizontalCuts.push_back(h);
        horizontalCuts.insert(horizontalCuts.begin(), 0);

        int n = horizontalCuts.size();
        int m = verticalCuts.size();

        int hc = 0;
        int vc = 0;
        long maxv = 0, maxh = 0;

        for (int i = 1; i < n; i++) {
            hc = horizontalCuts[i] - horizontalCuts[i - 1];
            if (maxh < hc)
                maxh = hc;
        }

        for (int j = 1; j < m; j++) {
            vc = verticalCuts[j] - verticalCuts[j - 1];
            if (maxv < vc)
                maxv = vc;
        }

        long ans = (maxv * maxh) % M;
        return ans;
    }
};
