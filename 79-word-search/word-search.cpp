class Solution {
public:

    bool helper(vector<vector<char>>& board, string word, int x, int y, int index)
    {
        if(index == word.size()) return true;
        
        // Check if the current position is out of bounds or doesn't match the word
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index])
            return false;

        // Temporarily mark the current cell as visited
        char temp = board[x][y];
        board[x][y] = '*'; // Assuming * won't appear in the board or the word
        
        // Explore adjacent cells
        bool found = helper(board, word, x - 1, y, index + 1) ||
                     helper(board, word, x + 1, y, index + 1) ||
                     helper(board, word, x, y - 1, index + 1) ||
                     helper(board, word, x, y + 1, index + 1);
        
        // Restore the original value of the current cell
        board[x][y] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(helper(board, word, i, j, 0)) // Start searching from each cell
                    return true;
            }
        }
        return false; 
    }
};