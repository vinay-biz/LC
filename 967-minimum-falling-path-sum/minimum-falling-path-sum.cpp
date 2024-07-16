class Solution {
public:
   int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); int ans = 1e9;
        vector<vector<int>> dp(n, vector<int> (n,-1e9));

        for(int i=0; i<n; i++) dp[0][i] = matrix[0][i];

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];

                int left = matrix[i][j];
                if(j > 0) left += dp[i-1][j-1];
                else left += 1e9;

                int right = matrix[i][j];
                if(j < n - 1) right +=  dp[i-1][j+1];
                else right += 1e9;

                dp[i][j] = min(min(left,right),up);
            }
        }

        for(int i=0; i<n; i++) ans = min(ans, dp[n-1][i]);
        return ans;
    }
};