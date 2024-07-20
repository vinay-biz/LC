class Solution {
public:
    int helper(vector<int>& coins, int n, int amount, vector<vector<int>>& dp)
    {
        if(amount == 0) return 0;
        if(n == 0)
        {
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e9; 
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        int notTake = 0 + helper(coins, n-1, amount, dp);
        int take = 1e9;
        if(coins[n] <= amount) take = 1+helper(coins, n, amount - coins[n], dp);

        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size()-1;
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans =  helper(coins, n, amount, dp);
        
        if(ans == 1e9) return -1;
        return ans;
    }
};