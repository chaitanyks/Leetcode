// https://leetcode.com/problems/maximal-rectangle/
// 85. Maximal Rectangle.cpp

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int ans = 0;
        int n = matrix.size();

        //Base case
        if (n == 0)
            return 0;

        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    // int ar=n;
                    int ac = m;

                    int ti = i;
                    int tj = j;

                    while (ti < n && matrix[ti][j] == '1') {
                        tj = j;
                        while (tj < m && matrix[ti][tj] == '1') {
                            tj++;
                        }
                        ti++;
                        ac = min(tj, ac);
                        int prod = (ti - i) * (ac - j);
                        ans = max(ans, prod);
                        // cout<<i<<" "<<j<<" "<<ti<<" "<<ac<<" "<<prod<<endl;
                    }

                }
            }
        }

        return ans;
    }
};
