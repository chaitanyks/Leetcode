// https://leetcode.com/problems/number-of-islands/
// 200. Number of Islands

class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            //left
            if (y + 1 < m && grid[x][y + 1] == '1' && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }

            //right
            if (y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }

            //top
            if (x + 1 < n && grid[x + 1][y] == '1' && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }

            //down
            if (x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited (n, vector < bool > (m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};
