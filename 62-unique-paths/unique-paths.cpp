class Solution {
public:
    int helper(int i, int j, int m , int n, vector<vector<int>> &dp)
    {
        if(i>=0 && j>=0 && i<m && j<n)
        {
            if(dp[i][j] != -1) return dp[i][j];

            if(i == m-1 && j == n-1) return dp[i][j] = 1;

            int down = helper(i+1,j,m,n, dp);
            int right = helper(i,j+1,m,n, dp); 
            
            return dp[i][j] = down + right; 

        }

        return 0;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n,-1));
        return helper(0,0,m,n,dp);
    }
};