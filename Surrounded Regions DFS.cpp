class Solution {
public:

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        if (!visited[i][j] && board[i][j] == 'O') {
            visited[i][j] = true;
            if (i - 1 >= 0)
                dfs(board, visited, i - 1, j);
            if (j - 1 >= 0)
                dfs(board, visited, i, j - 1);

            if (i + 1 < m)
                dfs(board, visited, i + 1, j);
            if (j + 1 < n)
                dfs(board, visited, i, j + 1);
        }
    }


    void solve(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        // cout<<m<<" "<<n<<endl;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(board, visited, 0, j);
            dfs(board, visited, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
