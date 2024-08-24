class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> prev(n, 0), curr(n, 0);
        curr[0] = grid[0][0];

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < n; ++j) {

                if(i == 0 && j == 0) continue;
                curr[j] = min(((i > 0) ? grid[i][j] + prev[j] : 1e9), ((j > 0) ? grid[i][j] + curr[j-1] : 1e9));
            }
            prev = curr;
        }

        return prev[n-1];
    }
};