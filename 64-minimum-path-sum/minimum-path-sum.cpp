class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size(); 
        
        vector<int> prev(m, 0), curr(m, 0);
        curr[0] = grid[0][0];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 && j == 0) continue;

                int up = (i > 0) ? prev[j] + grid[i][j] : 1e9;
                int left = (j > 0) ? curr[j-1] + grid[i][j] : 1e9;

                curr[j] = min(up,left);
            }

            prev = curr;
            curr = vector<int> (m,0);
        }
        return prev[m-1];
    }
};