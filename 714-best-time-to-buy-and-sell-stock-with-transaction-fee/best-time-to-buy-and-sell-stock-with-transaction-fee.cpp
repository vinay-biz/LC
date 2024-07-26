class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int curr0=0, curr1=0, ahead0=0, ahead1=0;
        
        for(int i = prices.size()-1; i >= 0; i--) {
            curr0 = max(ahead1 - prices[i] - fee, ahead0);
            curr1 = max(ahead0 + prices[i],ahead1);

            ahead0 = curr0; ahead1 = curr1;
        }

        return ahead0;
    }
};