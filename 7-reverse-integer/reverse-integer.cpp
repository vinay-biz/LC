class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x < 0) neg = true;
        x = abs(x);
        
        long long rev = 0;
        while(x > 0){
            int mod = x%10;
            rev = rev*10 + mod;
            x = x/10;

            if(rev > INT_MAX) return 0;
        }

        if(neg) return -1*rev;
        return rev;
    }
};