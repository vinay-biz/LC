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
        int n = price.size(); vector<vector<int>> dp(n+1, vector<int> ((k*2)+1, 0));

        for(int i=n-1; i >= 0; i--) {
            for(int j=(k*2)-1; j >= 0; j--)
            {
                int buy=0, sell = 0;
                if(j % 2 == 0) buy = dp[i+1][j+1] - price[i];
                if(j % 2 == 1) sell = dp[i+1][j+1] + price[i];
                int none = dp[i+1][j];

                dp[i][j] = max(max(buy,sell),none);
            }
        }

        return dp[0][0];
    }
};