class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        int n = price.size(); vector<vector<int>> dp(n+1, vector<int> ((k*2)+1, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int j= (k*2)-1 ; j >= 0; j--)
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