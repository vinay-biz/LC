class Solution {
public:
    


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;

        for(int i=1; i<=amount; i++)
        {
            for(int j=0; j<coins.size(); j++)
            {
                if(coins[j] <= i)
                {
                    int temp = 1 + dp[i - coins[j]];
                    dp[i] = min(dp[i], temp);
                }
            }
        }

        if(dp[amount] == 1e9 ) return -1;
        return dp[amount];
    }
};