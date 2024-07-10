class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>> &vis, int i, int j)
    {
        if(i >= 0 && j >=0 && i < board.size() && j < board[0].size() && 
            board[i][j] == 'O' && vis[i][j] == 0 )
        {
            vis[i][j] = 1;

            dfs(board,vis,i+1,j);
            dfs(board,vis,i-1,j);
            dfs(board,vis,i,j+1);
            dfs(board,vis,i,j-1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        //For boundary rows
        for(int i=0; i<n; i++)
        {
            //left row
            if(board[i][0] == 'O') dfs(board, vis, i, 0);

            //right row
            if(board[i][m-1] == 'O') dfs(board, vis, i, m-1);
        }

        //For boundary columns
        for(int i=0; i<m; i++)
        {
            //top column
            if(board[0][i] == 'O') dfs(board, vis, 0, i);
            
            //bottom column
            if(board[n-1][i] == 'O') dfs(board, vis, n-1, i);
            
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] == false && board[i][j] == 'O')
                board[i][j] = 'X';
            }
        }
    }
};