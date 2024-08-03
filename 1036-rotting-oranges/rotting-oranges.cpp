class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int m = grid.size();
        int n = grid[0].size();

        int freshCount = 0;
        queue<pair<int,int>> q;

        int minutes = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) freshCount++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        if(freshCount == 0) return 0;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i <sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();


                if(x!=0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                    freshCount--;
                }
                
                if(x!=m-1 && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                    freshCount--;
                }
                
                if(y!=0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                    freshCount--;
                }
                
                if(y!=n-1 && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                    freshCount--;
                }
            }
            
            minutes++;
        }

        if(freshCount == 0) return minutes-1;
        return -1;
    }
};