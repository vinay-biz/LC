class Solution {
public:
    int maxProfit(vector<int>& price) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int buy = 0;
        int ans = 0;

        for(int i=0; i<price.size(); ++i)
        {
            if(price[i] < price[buy]) buy = i;
            ans = max(ans, price[i] - price[buy]);
        }

        return ans;
    }
};