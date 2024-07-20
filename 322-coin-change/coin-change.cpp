class Solution {
public:
    int helper(vector<int>& coins, int n, int amt, vector<int>& dp)
    {
        if(amt == 0) return 0;

        int res = 1e9;

        if(dp[amt] != -1) return dp[amt];

        for(int i=0; i<coins.size(); i++)
        {
            if(coins[i] <= amt)
            {
                int temp = 1 + helper(coins, n, amt - coins[i], dp);
                
                res = min(res, temp);
            }
        }

        return dp[amt] = res;
    }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans = helper(coins, n-1, amount, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};