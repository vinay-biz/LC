class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int ans = 0;
        int x = 0;
        bool neg = false;

        while(s[x] == ' ') x++;
        if(s[x] == '-') {
            neg = true;
            x++;
        }
        else if(s[x] == '+') x++;


        for(int i = x; i < n; i++) {
            if(s[i] < '0' || s[i] > '9') break;

            int temp = s[i] - '0';
            if((long long)ans*10+(long long)temp > INT_MAX){
                if(neg) return INT_MIN;
                return INT_MAX;
            }
            ans =  ans*10 + temp;
        }

        if(neg) ans *= -1;
        return ans;
    }
};