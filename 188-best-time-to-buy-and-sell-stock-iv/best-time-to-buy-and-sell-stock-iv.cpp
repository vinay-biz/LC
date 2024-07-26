class Solution {
public:
    int helper(vector<int>& price, int k, int n, int curr, vector<vector<int>>& dp)
    {
        if(n == price.size() || curr == k * 2) return 0;

        if(dp[n][curr] != -1) return dp[n][curr];

        int buy = 0, sell = 0;
        if(curr % 2 == 0) buy = helper(price, k, n+1, curr+1, dp) - price[n];
        if(curr % 2 == 1) sell = helper(price, k, n+1, curr+1, dp) + price[n];
        int none = helper(price, k, n+1, curr, dp);

        return dp[n][curr] = max(max(buy, sell), none);
    }
    int maxProfit(int k, vector<int>& price) {
        int n = price.size(); vector<vector<int>> dp(n, vector<int> ((k*2), -1));
        return helper(price, k, 0, 0, dp);
    }
};