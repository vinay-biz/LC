class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(5, 0), curr(5,0);

        for(int i = n-1; i>=0; i--){
            for(int j=3; j>=0; j--){
                int buy = 0, sell = 0;
                if(j == 0 || j == 2)
                    buy = ahead[j+1] - prices[i];
                else if(j == 1 || j == 3)
                    sell = ahead[j+1] + prices[i];
                int none = ahead[j];

                curr[j] = max(max(buy,sell),none);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};