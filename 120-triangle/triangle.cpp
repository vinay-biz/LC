class Solution {
public:
    int helper(vector<vector<int>>& triangle, int n, int row, int col, vector<vector<int>>& dp)
    {
        if(row < n && col <= row)
        {
            if(dp[row][col] != -1) return dp[row][col];
            int left = triangle[row][col] + helper(triangle, n, row+1, col, dp);
            int right = triangle[row][col] + helper(triangle, n, row+1, col+1, dp);

            return dp[row][col] = min(left,right);
        }

        return 0;
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n); for(int i=0; i<n; i++) dp[i] = vector<int> (i+1,-1);

        return helper(triangle, n, 0, 0,dp); 
    }
};