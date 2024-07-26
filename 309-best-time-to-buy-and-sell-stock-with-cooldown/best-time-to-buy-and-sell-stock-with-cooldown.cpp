class Solution {
public:
    int maxProfit(vector<int>& price) {
        vector<int> curr(2, 0), ahead1(2, 0), ahead2(2,0);

        for(int i = price.size()-1; i >= 0; i--)
        {
            curr[0] = max(ahead1[1] - price[i], ahead1[0]);
            curr[1] = max(ahead2[0] + price[i], ahead1[1]);

            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[0];
    }
};