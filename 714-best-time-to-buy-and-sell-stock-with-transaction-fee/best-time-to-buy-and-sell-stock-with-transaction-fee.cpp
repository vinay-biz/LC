class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0), ahead(2,0);
        
        for(int i = n-1; i >= 0; i--) {
            curr[0] = max(ahead[1] - prices[i] - fee, ahead[0]);
            curr[1] = max(ahead[0] + prices[i],ahead[1]);

            ahead = curr;
        }

        return ahead[0];
    }
};