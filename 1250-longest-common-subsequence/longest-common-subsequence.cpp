class Solution {
public:
    int LCS(string& str1, string& str2, int n, int m, vector<vector<int>>& dp)
    {
        //Base Case, incase no length is left we cannot increase subsequence length
        if(n<0 || m<0) return 0;

        //Check DP
        if(dp[n][m] != -1) return dp[n][m];

        //If the two char match, they are common, so add one and continue
        if(str1[n] == str2[m]) return dp[n][m] = 1 + LCS(str1, str2, n-1, m-1, dp);

        //Do take , not take on both sides
        return dp[n][m] = max(LCS(str1, str2, n-1, m, dp), LCS(str1, str2, n, m-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //Initialize DP array
        vector<vector<int>> dp(n, vector<int> (m,-1));

        //Perform LCS
        return LCS(text1, text2, n-1, m-1, dp);
    }
};