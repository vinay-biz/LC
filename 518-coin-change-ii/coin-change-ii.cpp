class Solution {
public:
    int helper(vector<int>& coins, int t, int n, vector<vector<int>>& dp)
    {
        if(t == 0) return 1; //We reached the sum
        if(n == 0) //If it is the last coin
        {
            if(t >= coins[0] && t%coins[0] == 0) return 1; //If current coins can satisfy
            return 0;
        }

        if(dp[n][t] != -1) return dp[n][t];

        int notTake = helper(coins, t, n-1, dp);
        int take = 0;
        if(coins[n] <= t) take = helper(coins, t - coins[n], n, dp);

        return dp[n][t] = take+notTake;
    }

    int change(int t, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (t+1, 0));

        for(int i=0; i<n; i++) dp[i][0] = 1;
        for(int i=coins[0]; i<=t; i++) {
            if(i%coins[0] == 0) dp[0][i] = 1;
            }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=t; j++)
            {
                int notTake = dp[i-1][j];
                int take = 0;
                if(coins[i] <= j) take = dp[i][j - coins[i]];

                dp[i][j] = take + notTake;
            }
        }


        return dp[n-1][t];
    }
};