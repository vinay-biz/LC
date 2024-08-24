class Solution {
public:
    int helper(vector<vector<int>>& arr, int m, int n, vector<vector<int>>& dp)
    {
        if(m >= arr.size() || n >= arr[0].size() || arr[m][n] == 1) return 0;
        if(m == arr.size()-1 && n == arr[0].size()-1) return 1;
        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = helper(arr, m+1, n, dp) + helper(arr, m, n+1, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(obstacleGrid, 0, 0, dp);
    }
};