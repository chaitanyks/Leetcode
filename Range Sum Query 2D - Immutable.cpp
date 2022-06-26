// https://leetcode.com/problems/range-sum-query-2d-immutable/
// 304. Range Sum Query 2D - Immutable

class NumMatrix {
public:
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>>&matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefixSum.resize(m, vector < int>(n));

        for (int i = 0; i < m; i++)
            prefixSum[i][0] = matrix[i][0];

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++)
                prefixSum[i][j] = prefixSum[i][j - 1] + matrix[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;

        for (int i = row1; i <= row2; i++)
            ans = ans + prefixSum[i][col2] - (col1 == 0 ? 0 : prefixSum[i][col1 - 1]);

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
