class Solution {
public:
    int numTrees(int N) {
        vector<int> dp(20, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int n = 3; n <= N; n++)
        {
            int ans = 0;
            for(int i=1; i <= n; i++) 
            {
                ans = ans + dp[i-1] * dp[n-i];
            }
            dp[n] = ans;
        }
        return dp[N];
    }
};