class Solution {
public:
    int change(int t, vector<int>& coins) {
        vector<int> prev(t+1,0), curr(t+1,0); for(int i=0; i<=t; i++) prev[i] = (i%coins[0] == 0);

        for(int i=1; i<coins.size(); i++){
            for(int j=0; j<=t; j++){
                int notTake = prev[j];
                int take = 0;
                if(coins[i] <= j) take = curr[j - coins[i]];

                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return prev[t];
    }
};