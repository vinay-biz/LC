class Solution {
public:
    int helper(vector<int>& piles, int sz, int M, int index, bool turn, vector<vector<vector<int>>> &dp) {
        if(index >= sz) return 0;
        if(dp[turn][M][index] != -1) return  dp[turn][M][index];

        int stones = 0 , result = turn ? -1 : INT_MAX;

        for(int X = 1; X <= min(2*M, sz - index); X++) {
            stones += piles[index + X - 1]; 
            if(turn) result = max(result, stones + helper(piles, sz, max(M, X), index + X, !turn, dp));
            else result = min(result, 0 + helper(piles, sz, max(M,X), index + X, !turn, dp));
        }

        return dp[turn][M][index] = result;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (101, vector<int>(101 , -1)));
        return helper(piles, piles.size(), 1, 0, true, dp);
    }
};