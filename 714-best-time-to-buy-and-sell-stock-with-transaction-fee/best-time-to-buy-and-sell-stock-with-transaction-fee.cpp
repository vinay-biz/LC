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
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1)); 
        return helper(prices, fee, 0, 0, dp);
    }
};