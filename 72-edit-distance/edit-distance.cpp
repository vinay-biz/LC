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
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(s, t, n-1, m-1, dp);
    }
};