class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = '2';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numberOfIslands(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> grid2 = grid;
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j] == 1){
                    dfs(grid2, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    int minDays(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int num = numberOfIslands(grid);
        if(num != 1) return 0;

        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int x = numberOfIslands(grid);
                    if(x > 1 || x < 1) return 1;
                    grid[i][j] = 1;
                }
            }
        } 

        return 2;       
    }
};