class Solution {
public:
    int helper(vector<int>& price, int n, int curr, vector<vector<int>>& dp)
    {
        if(n >= price.size()) return 0;

        if(dp[n][curr] != -1) return dp[n][curr];

        int buy = 0, sell = 0;
        if(!curr) buy = helper(price, n+1, !curr, dp) - price[n];
        if(curr) sell = helper(price, n+2, !curr, dp) + price[n];
        int none = helper(price, n+1, curr, dp);

        return dp[n][curr] = max(max(buy,sell),none);
    }
    int maxProfit(vector<int>& price) {
        int n = price.size(); vector<vector<int>> dp(n, vector<int> (2, -1));
        return helper(price, 0, 0, dp);
    }
};