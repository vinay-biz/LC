class Solution {
public:
    bool helper(string& s, string& p, int n, int m, vector<vector<int>>& dp)
    {
        if(m < 0){
            if(n < 0) return true;
            return false; }
        if(n < 0){
            for(int i=m; i>=0; i--)
            {
                if(p[i] != '*' ) return false;
            }
            return true;
        }
            
        if(dp[n][m] != -1) return dp[n][m];

        if(s[n] == p[m] || p[m] == '?') return dp[n][m] = helper(s, p, n-1, m-1, dp);

        if(p[m] == '*') return dp[n][m] = (helper(s, p, n-1, m, dp) || helper(s, p, n, m-1, dp));

        return dp[n][m] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return helper(s, p, n-1, m-1, dp);
    }
};