class Solution {
public:
    int change(int t, vector<int>& coins) {
        vector<int> dp(t+1,0); for(int i=0; i<=t; i++) dp[i] = (i%coins[0] == 0);

        for(int i=1; i<coins.size(); i++){
            for(int j=0; j<=t; j++){
                int notTake = dp[j];
                int take = 0;
                if(coins[i] <= j) take = dp[j - coins[i]];

                dp[j] = take + notTake;
            }
        }
        return dp[t];
    }
};