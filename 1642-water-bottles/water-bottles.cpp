class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles + (numBottles-1)/(numExchange-1);
        return n;
    }
};