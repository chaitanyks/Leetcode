class Solution {
public:
    void bfs(vector<vector<char>>& board,vector<vector<char>>& temp,int n,int m)
    {
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                q.push({i,0});
            if(board[i][n-1] == 'O' )
                q.push({i,n-1});
        }
        
        for(int j=1;j<n-1;j++)
        {
            if(board[0][j]=='O')
                q.push({0,j});
            if(board[m-1][j] =='O')
                q.push({m-1,j});
        }
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            temp[i][j]='1';
            q.pop();
            // cout<<i<<" "<<j<<" "<<q.size()<<endl;
            //up
            if(i-1>=0 && board[i-1][j]=='O' && temp[i-1][j]!='1')
                q.push({i-1,j});
            //down
            if(i+1<m && board[i+1][j]=='O' && temp[i+1][j]!='1')
                q.push({i+1,j});
            // left
            if(j-1>=0 && board[i][j-1]=='O' && temp[i][j-1]!='1')
                q.push({i,j-1});
            //right
            if(j+1<n && board[i][j+1]=='O' && temp[i][j+1]!='1')
                q.push({i,j+1});            
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(temp[i][j]!='1')
                    board[i][j]='X';
            }
        }
    }
    
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // cout<<m<<" "<<n<<endl;
       
        vector<vector<char>> temp;
        temp = board;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp[i][j]='X';
            }
        }
        
        bfs(board,temp,n,m);
    }
};
