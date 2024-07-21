class Solution {
public:
    int change(int t, vector<int>& coins) {
        vector<int> dp(t + 1, 0);
        dp[0] = 1; // There is one way to make amount 0, that is using no coins.

        for(int coin : coins) {
            for(int j = coin; j <= t; j++) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[t];
    }
};
