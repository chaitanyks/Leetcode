class Solution {
public:

    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> grid1;
        grid1 = grid;

        int time = 0;
        bool check = true;
        while (check) {
            check = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        //up
                        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                            grid1[i - 1][j] = 2;
                            check = true;
                        }

                        //down
                        if (i + 1 < m && grid[i + 1][j] == 1) {
                            grid1[i + 1][j] = 2;
                            check = true;
                        }

                        //right
                        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                            grid1[i][j - 1] = 2;
                            check = true;
                        }

                        //left
                        if (j + 1 < n && grid[i][j + 1] == 1) {
                            grid1[i][j + 1] = 2;
                            check = true;
                        }

                    }
                }
            }
            grid = grid1;
            if (!check)
                break;
            time++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout<<grid[i][j]<<" ";
                if (grid1[i][j] == 1)
                    return -1;
            }
            // cout<<endl;
        }

        return time;

    }
};
