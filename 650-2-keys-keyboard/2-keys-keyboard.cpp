class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int d = 2;

        while(n > 1) //We know for 1 it is 0
        {
            while(n%d == 0) {
                ans += d;
                n /= d;
            }

            d++;
        }

        return ans;
    }
};