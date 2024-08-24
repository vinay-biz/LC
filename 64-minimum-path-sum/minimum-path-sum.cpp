class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {

                if(i == 0 && j == 0) continue;

                int up  = (i > 0) ? grid[i][j] + dp[i-1][j] : 1e9;
                int right = (j > 0) ? grid[i][j] + dp[i][j-1] : 1e9;

                dp[i][j] = min(up, right);
            }
        }

        return dp[m-1][n-1];
    }
};