class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int n, int m, vector<vector<int>>& dp)
    {
        if(n >= 0 && m >=0 && obstacleGrid[n][m] == 0)
        {
            if(dp[n][m] != -1) return dp[n][m];
            if(n == 0 && m == 0) return 1;

            int up = helper(obstacleGrid, n-1, m, dp );
            int left = helper(obstacleGrid, n, m-1, dp);

            return dp[n][m] = left+up;
        }
        
        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int> (m,-1));
        return helper(obstacleGrid, n-1, m-1, dp);
    }   
};