class Solution {
public:
    int maxProfit(vector<int>& price) {
        int ans = 0;
        for(int i=1; i<price.size(); i++)
        {
            if(price[i] > price[i-1]) ans+= price[i] - price[i-1];
        }
        return ans;
    }
};