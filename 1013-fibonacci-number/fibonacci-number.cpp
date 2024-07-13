class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0; 
                
        int prev2 = 0;
        int prev = 1;
        int curr;

        for(int i=2; i<=n; i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr; 
        }

        return prev;
    }
};