class Solution {
public:
    int change(int t, vector<int>& coins) {
        int n = coins.size(); vector<vector<int>> dp(n, vector<int> (t+1, 0));
        for(int i=0; i<=t; i++) dp[0][i] = (i%coins[0] == 0);

        for(int i=1; i<n; i++){
            for(int j=0; j<=t; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(coins[i] <= j) take = dp[i][j - coins[i]];

                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][t];
    }
};