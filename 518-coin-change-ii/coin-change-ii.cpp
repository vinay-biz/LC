class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0)); dp[0][0] = 1;

        for(int i=1; i<= n; i++){
            for(int j=0; j<=sum; j++){
                dp[i][j] += dp[i-1][j];
                if((j - coins[i-1]) >= 0) dp[i][j] += dp[i][j - coins[i - 1]];
            }   
        }
        return dp[n][sum];
    }
};