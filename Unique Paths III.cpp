
class Solution {
public:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int ei, int ej, int count0) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        // cout<<i<<" "<<j<<" "<<" "<<count0<<endl;
        if (i == ei && j == ej) {
            if (count0 == -1)
                return 1;
            else
                return 0;
        }

        visited[i][j] = true;

        //up
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] != -1)
            ans += dfs(grid, visited, i - 1, j, ei, ej, count0 - 1);
        //down
        if (i + 1 < m && !visited[i + 1][j] && grid[i + 1][j] != -1)
            ans += dfs(grid, visited, i + 1, j, ei, ej, count0 - 1);
        //left
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] != -1)
            ans += dfs(grid, visited, i, j - 1, ei, ej, count0 - 1);
        //right
        if (j + 1 < n && !visited[i][j + 1] && grid[i][j + 1] != -1)
            ans += dfs(grid, visited, i, j + 1, ei, ej, count0 - 1);

        visited[i][j] = false;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>> &grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int si,sj,ei,ej,count0=0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }

                if (grid[i][j] == 2) {
                    ei = i;
                    ej = j;
                }

                if (grid[i][j] == 0) {
                    count0++;
                }

            }
        }

        return dfs(grid, visited, si, sj, ei, ej, count0);
    }
};
