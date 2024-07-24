class Solution {
public:
    int helper(string& s, string& t, int i, int j, vector<vector<int>>& dp)
    {
        
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] =  helper(s, t, i-1, j-1, dp);

        return dp[i][j] =  1 + min(helper(s, t, i, j-1, dp)
                        ,min(helper(s, t, i-1, j, dp), helper(s, t, i-1, j-1, dp)));
    }
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=0; i<=n; i++) dp[i][0] = i;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }

        return dp[n][m];
    }
};