class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        vector<int> prev(m,0);
        vector<int> curr(m,0); curr[0] = 1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 && j == 0) continue;

                if(obstacleGrid[i][j] == 0)
                {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j-1] : 0;

                    curr[j] = up + left;
                }
                else curr[j] = 0;
            }
             prev = curr;
             curr = vector<int> (m,0);
        }
        return prev[m-1];
    }   
};