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
        int n = price.size(); vector<vector<int>> dp(n+2, vector<int> (2, 0));
    

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 1; j >= 0; j--)
            {
                int buy = 0, sell = 0;
                if(!j) buy = dp[i+1][!j] - price[i];
                if(j)  sell = dp[i+2][!j] + price[i];
                int none = dp[i+1][j];

                dp[i][j] = max(max(buy,sell),none);
            }
        }
        return dp[0][0];
    }
};