class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //Initialize DP array
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i=0; i<n; i++) dp[i][0] = 0; //Base case
        for(int j=0; j<m; j++) dp[0][j] = 0; //Base case

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; //Incase common
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]); //If not common, take - not take
            }
        }

        return dp[n][m];
    }
};