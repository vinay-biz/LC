class Solution {
public:
    int helper(string& str1, string& str2, int n, int m, vector<vector<int>>& dp)
    {
        if(n < 0 || m < 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(str1[n] == str2[m]) return 1 + helper(str1, str2, n-1, m-1, dp);

        return dp[n][m]= max( helper(str1, str2, n-1, m, dp), helper(str1, str2, n, m-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(text1, text2, n-1, m-1, dp);
    }
};