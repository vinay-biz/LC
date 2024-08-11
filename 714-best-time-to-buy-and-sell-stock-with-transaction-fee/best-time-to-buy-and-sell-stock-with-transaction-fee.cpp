class Solution {
public:
   
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0), ahead(2,0);
        int curr0 = 0, curr1 = 0, ahead0 = 0, ahead1 = 0;

        for(int i=n-1; i >= 0; i--)
        {

            curr0 = max(ahead1 - prices[i] - fee ,ahead0); 
            curr1 = max(ahead0 + prices[i]       ,ahead1); 
            ahead0 = curr0;
            ahead1 = curr1;
        }
        return curr0;
    }
};