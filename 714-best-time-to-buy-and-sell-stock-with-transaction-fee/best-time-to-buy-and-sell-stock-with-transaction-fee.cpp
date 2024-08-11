class Solution {
public:
    int helper(vector<int>& prices, int fee, int i, int curr, vector<vector<int>>& dp)
    {
        if(i == prices.size()) return 0;
        if(dp[i][curr] != -1) return dp[i][curr];

        int buy = 0, sell = 0;
        if(curr == 0) buy = helper(prices, fee, i+1, 1, dp) - prices[i] - fee;
        else sell = helper(prices, fee, i+1, 0, dp) + prices[i];
        int none = helper(prices, fee, i+1, curr, dp);

        return dp[i][curr] = max(none, max(buy,sell));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        for(int i=n-1; i >= 0; i--)
        {
            for(int j=1; j >=0; j--)
            {
                int buy = 0, sell = 0;
                if(j == 0) buy = dp[i+1][1] - prices[i] - fee;
                else sell = dp[i+1][0] + prices[i];
                int none = dp[i+1][j];

                dp[i][j] = max(buy,max(sell,none)); 
            }
        }
        return dp[0][0];
    }
};