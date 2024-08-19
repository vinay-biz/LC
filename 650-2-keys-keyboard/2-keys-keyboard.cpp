class Solution {
public:
    int helper(int n, int currLen, int pasteLen, vector<vector<int>>& dp)
    {
        if(currLen == n) return 0; //Don't need any more operations

        if(currLen > n) return 1001; //currLen can never exceed N

        if(dp[currLen][pasteLen] != -1) return dp[currLen][pasteLen];

        int cpyPaste = 2 + helper(n, currLen*2, currLen, dp);
        int paste = 1 + helper(n, currLen + pasteLen, pasteLen, dp);

        return dp[currLen][pasteLen] =min(cpyPaste, paste);

    }
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int> (n, -1));
        return 1 + helper(n, 1, 1, dp);
    }
};