class Solution {
public:
    int minDistance(string str1, string str2) {
        int n = str1.length(),  m = str2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]) 
                    curr[j] = prev[j-1];
                else curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));
            }
            prev = curr;
        }

        return prev[m];
    }
};