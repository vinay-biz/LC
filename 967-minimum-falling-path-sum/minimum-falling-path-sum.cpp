class Solution {
public:
    int helper(vector<vector<int>>& matrix, int n, int row, int col, vector<vector<int>>& dp)
    {
        if(col < 0 || col >= n) return 1e9;
        if(dp[row][col] != -1e9) return dp[row][col];
        if(row == 0) return matrix[row][col];

        int up = matrix[row][col] + helper(matrix,n,row-1,col,dp);
        int left = matrix[row][col] + helper(matrix,n,row-1,col-1,dp);
        int right = matrix[row][col] + helper(matrix,n,row-1,col+1,dp);

        return dp[row][col] = min(min(up,left),right);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;

        vector<vector<int>> dp(n, vector<int> (n,-1e9));

        for(int i=0; i<n; i++)
        {
            int temp = helper(matrix, n, n-1, i, dp);
            ans = min(ans, temp);
        }

        return ans;
    }
};