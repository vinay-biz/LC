class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        vector<int> prev(m+1,0), curr(m+1,0);
        
        prev[0] = 1; curr[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--)
            {
                if(s[i-1] == t[j-1]) {
                    if(prev[j-1] <= INT_MAX - prev[j]) 
                    prev[j] = prev[j-1] + prev[j];
                }
                else prev[j] = prev[j];
            }
        } 

        return prev[m];
    }
};