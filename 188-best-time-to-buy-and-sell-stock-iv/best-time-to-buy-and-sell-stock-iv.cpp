class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        int n = price.size(); vector<vector<int>> dp(n+1, vector<int> ((k*2)+1, 0));
        vector<int> ahead((k*2)+1, 0), curr((k*2)+1, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int j= (k*2)-1 ; j >= 0; j--)
            {
                int buy=0, sell = 0;
                if(j % 2 == 0) buy = ahead[j+1] - price[i];
                if(j % 2 == 1) sell = ahead[j+1] + price[i];
                int none = ahead[j];

                curr[j] = max(max(buy,sell),none);
            }
            ahead = curr;
        }

        return ahead[0];
    }
};