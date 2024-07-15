class Solution {
public:
    int helper(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp)
    {
        if(n >= 0 && m >=0)
        {
            if(dp[n][m] != -1) return dp[n][m];

            if(n==0 && m==0) return grid[0][0];

            int up = helper(grid, n-1, m,dp) + grid[n][m];
            int left = helper(grid, n, m-1,dp) + grid[n][m];

            return dp[n][m] = min(up, left);
        }

        return 1e9;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size(); 
        vector<vector<int>> dp(n , vector<int> (m,-1));
        
        return helper(grid, n-1, m-1, dp);
    }
};