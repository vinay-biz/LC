class Solution {
public:
    // int tribonacci(int n) {
    //     if (n == 0) {
    //         return 0;
    //     } else if (n == 1 || n == 2) {
    //         return 1;
    //     } else {
    //         return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    //     }
    // }

    int tribonacci(int n)
    {
        if(n == 0 || n==1) return n;
        vector<int> dp(40,0);
        int prev2 = 0;
        int prev1 = 1;
        int prev = 1;
        int curr;

        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 1;

        for(int i=3; i<=n; i++)
        {
            curr = prev+prev1+prev2;

            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }

        return prev;
    }

};