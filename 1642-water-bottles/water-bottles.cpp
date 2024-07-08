class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int carry = 0;
        int prev = 0;
        
        while(numBottles)
        {
            ans += numBottles;
            prev = carry;
            carry = (numBottles+prev)%numExchange;
            numBottles = (numBottles+prev)/numExchange;            
        }

        return ans;
    }
};