class Solution {
public:
    int helper(vector<int>& piles, int sz, int M, int index, bool turn, vector<vector<vector<int>>> &dp) 
    {
        if(index >= sz) //If we have reached out of bounds, BASE CASE 
            return 0;

        if(dp[turn][M][index] != -1) 
            return  dp[turn][M][index]; //DP step

        int stones = 0 ; //Count of stones we will take
        int result = turn ? -1 : INT_MAX; //Becase we take max in one case and min in other

        for(int X = 1; X <= min(2*M, sz - index); X++)  //Make sure to add boundary check by using min
        {
            stones += piles[index + X - 1]; //Add the current stones 
            if(turn) //Alice turn, we try to maximaize stones 
                result = max(result, stones + helper(piles, sz, max(M, X), index + X, !turn, dp));
            else //Bob's turn, we try to minimize the stones 
                result = min(result, 0 + helper(piles, sz, max(M,X), index + X, !turn, dp));
        }

        return dp[turn][M][index] = result;
    }
    int stoneGameII(vector<int>& piles) {
        //Check constraints for why
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (101, vector<int>(101 , -1)));
        return helper(piles, piles.size(), 1, 0, true, dp);
    }
};