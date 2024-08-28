class Solution {
public:
    void helper(vector<vector<int>>& grid, vector<vector<int>>& check, int i, int j, bool& flag) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;

        grid[i][j] = 2;
        if(check[i][j] != 1) flag = false;
        helper(grid, check, i+1, j, flag);
        helper(grid, check, i-1, j, flag);
        helper(grid, check, i, j+1, flag);
        helper(grid, check, i, j-1, flag);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;

        for(int i = 0; i < grid2.size(); ++i) {
            for(int j = 0; j < grid2[0].size(); ++j) {
                if(grid2[i][j] == 1)
                    {
                        bool flag = true;
                        helper(grid2, grid1, i , j, flag);
                        if(flag) count++;
                    }
            }
        }

        return count;
    }
};