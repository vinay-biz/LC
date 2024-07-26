class Solution {
public:
    int helper(vector<int>& prices, int fee, int n, int curr, vector<vector<int>>& dp)
    {
        if(n == prices.size()) return 0;

        if(dp[n][curr] != -1) return dp[n][curr];

        int buy = 0, sell = 0;
        if(curr == 0) buy = helper(prices, fee, n+1, 1, dp) - prices[n] - fee;
        if(curr == 1) sell = helper(prices, fee, n+1, 0, dp) + prices[n];
        int none = helper(prices, fee, n+1, curr, dp);

        return dp[n][curr] =  max(max(buy,sell),none);

    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return helper(prices, fee, 0, 0, dp);
    }
};