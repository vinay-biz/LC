class Solution {
public:
    void helper(vector<vector<int>>& matrix, int row, int col)
    {
        for(int i=0; i<matrix.size(); i++) matrix[i][col] = 0;
        for(int j=0; j<matrix[0].size(); j++) matrix[row][j] = 0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;

        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0) zeros.push_back({i,j});
            }
        }

        for(auto x : zeros)
        {
            helper(matrix, x.first, x.second);
        }
    }
};