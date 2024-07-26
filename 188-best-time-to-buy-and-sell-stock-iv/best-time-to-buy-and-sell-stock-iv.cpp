class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n = k*2;
        vector<int> ahead(n+1, 0), curr(n+1, 0);

        for(int i = price.size()-1; i >= 0; i--) {
            for(int j= n-1 ; j >= 0; j--)
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