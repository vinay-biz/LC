class Solution {
public:
    int maxProfit(vector<int>& price) {
        int curr0=0, curr1=0, ahead10 = 0,ahead11 = 0, ahead20 = 0,ahead21 = 0;

        for(int i = price.size()-1; i >= 0; i--)
        {
            curr0 = max(ahead11 - price[i], ahead10);
            curr1 = max(ahead20 + price[i], ahead11);

            ahead20 = ahead10;ahead21 = ahead11;
            ahead10 = curr0;ahead11 = curr1;
        }
        return ahead10;
    }
};