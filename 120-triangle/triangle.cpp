class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); 
        //vector<vector<int>> dp(n); for(int i=0; i<n; i++) dp[i] = vector<int> (i+1,-1);
        vector<int> curr(n,0), next(n,0);

        for(int i=0; i<n; i++) next[i] = triangle[n-1][i];

        for(int i = n-2; i >= 0; i--)
        {
            for(int j=0; j<=i; j++)
            {
                int down = triangle[i][j] + next[j];
                int downRight = triangle[i][j] + next[j+1];

                curr[j] = min(down,downRight);
            }

            next = curr;
        }

        return next[0];
    }
};