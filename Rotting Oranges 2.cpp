class Solution {
public:

    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            pair<int, pair<int, int>> temp;
            temp = q.front();
            q.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            if (ans < temp.first)
                ans = temp.first;

            //up
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({temp.first + 1, {i - 1, j}});
            }

            //down
            if (i + 1 < m && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({temp.first + 1, {i + 1, j}});
            }

            //left
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({temp.first + 1, {i, j - 1}});
            }

            //right
            if (j + 1 < n && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({temp.first + 1, {i, j + 1}});
            }

        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout<<grid[i][j]<<" ";
                if (grid[i][j] == 1)
                    return -1;
            }
            // cout<<endl;
        }

        return ans;

    }
};
