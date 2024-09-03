class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int& count)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] <= 0) return;

        count = count + grid[i][j];
        grid[i][j] = -1;
        dfs(grid,i-1,j, count);
        dfs(grid,i+1,j, count);
        dfs(grid,i,j-1, count);
        dfs(grid,i,j+1, count);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};
