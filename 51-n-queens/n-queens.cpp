class Solution {
public:

    void helper(vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow,
                vector<int>& upperDaig, vector<int>& lowerDaig, int n, int col)
    {
        if(col == n) //We have fixed all the columns!! Solved
        {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(leftRow[row]==0 &&               //Left row
                lowerDaig[row + col] == 0 &&    //Lower Daig check
                upperDaig[n-1 + col - row] == 0)//Upper Daig check
            {
                board[row][col] = 'Q'; //Set the Queen in this row
                
                leftRow[row] = 1;             //Set the hashes
                lowerDaig[row+col] = 1;
                upperDaig[n-1 +col -row] = 1;

                helper(board, ans, leftRow, upperDaig, lowerDaig, n, col+1);

                //Backtrack
                board[row][col] = '.';

                leftRow[row] = 0;             //Reset the hashes
                lowerDaig[row+col] = 0;
                upperDaig[n-1 +col -row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        std::ios_base::sync_with_stdio(false);std::cout.tie(nullptr);std::cin.tie(nullptr);
        vector<vector<string>> ans; //Create ans array

        vector<string> board(n); //Create the board
        string s(n,'.');
        for(int i=0; i<n; i++) board[i] = s;

        vector<int> leftRow(n,0);         //Check for left daigonal
        vector<int> upperDaig(2*n+1, 0); //Check for upper daigonal
        vector<int> lowerDaig(2*n+1,0); //Check for lower daigonal

        helper(board, ans, leftRow, upperDaig, lowerDaig, n, 0);

        return ans;
    }
};