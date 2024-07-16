class Solution {
public:
    int helper(vector<vector<int>>& triangle, int n, int row, int col, vector<vector<int>>& dp)
    {
        if(row == n-1) return triangle[row][col]; //Base case
        if(dp[row][col] != -1) return dp[row][col];
        int down = triangle[row][col] + helper(triangle, n, row+1, col, dp);
        int downRight = triangle[row][col] + helper(triangle, n, row+1, col+1, dp);

        return dp[row][col] = min(down, downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n); for(int i=0; i<n; i++) dp[i] = vector<int> (i+1,-1);
        return helper(triangle, n, 0, 0, dp); 
    }
};