class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //Initialize DP array
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j=0; j<m; j++) prev[j] = 0; //Base case

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1]; //Incase common
                else curr[j] = max(curr[j-1], prev[j]); //If not common, take - not take
            }
            prev = curr;
        }

        return prev[m];
    }
};