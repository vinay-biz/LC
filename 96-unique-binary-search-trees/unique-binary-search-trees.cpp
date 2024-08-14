class Solution {
public:
    int helper(int n, vector<int>& dp)
    {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i=1; i < n+1; i++)
        {
            ans += helper(i-1, dp) * helper(n - i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};