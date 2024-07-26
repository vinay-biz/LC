class Solution {
public:
    int helper(vector<int>& price, int n, int curr, vector<vector<int>>& dp)
    {
        if(n == price.size() || curr == 4) return 0;

        if(dp[n][curr] != -1) return dp[n][curr];

        int buy = 0, sell = 0;
        if(curr == 0 || curr == 2) buy = helper(price, n+1, curr+1, dp) - price[n];
        if(curr == 1 || curr == 3) sell = helper(price, n+1, curr+1, dp) + price[n];
        int none = helper(price, n+1, curr, dp);

        return dp[n][curr] =  max(max(buy,sell),none);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (5, 0));

        for(int i = n-1; i>=0; i--)
        {
            for(int j=3; j>=0; j--)
            {
                int buy = 0, sell = 0;
                if(j == 0 || j == 2)
                    buy = dp[i+1][j+1] - prices[i];
                else if(j == 1 || j == 3)
                    sell = dp[i+1][j+1] + prices[i];
                int none = dp[i+1][j];

                dp[i][j] = max(max(buy,sell),none);
            }
        }
        return dp[0][0];
    }
};