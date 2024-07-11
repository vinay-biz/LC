class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        std::ios_base::sync_with_stdio(false);std::cout.tie(nullptr);std::cin.tie(nullptr);
        helper(board);
    }

    bool helper(vector<vector<char>>& board)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++) //Go over the whole board
            {
                if(board[i][j] == '.') //if it is a blank
                {
                    for(char num='1'; num <='9'; num++) //Try filling up numbers
                    {
                        if(isValid(board, i, j, num)) //Check if a number is valid to be filled
                        {
                            board[i][j] =  num; //Number to ascii

                            if(helper(board)==true) return true; //Check if board is legal

                            else board[i][j] = '.'; //backtrack
                        }
                    }

                    return false; //No number can be filled
                }
            }
        }

        return true; //All numbers were filled
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char num)
    {
        for(int i=0; i<=8; i++)
        {
            if(board[i][col] == num) return false; //Check rwo
            if(board[row][i] == num) return false; //check col

            if(board[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == num) return false;
        }

        return true;
    }
};