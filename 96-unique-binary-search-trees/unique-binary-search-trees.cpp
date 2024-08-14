class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(20, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            int ans = 0;
            for(int j=1; j <= i; j++) 
            {
                ans += dp[j-1] * dp[i-j];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};