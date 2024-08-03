class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), freshCount = 0, minutes = 0;
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) freshCount++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        if(freshCount == 0) return 0;

        int a[] = {1, -1, 0, 0};
        int b[] = {0 , 0, 1, -1};

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i <sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++)
                {
                    int nx = x + a[i];
                    int ny = y + b[i];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1)
                    continue;

                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                    freshCount--;
                }
               
            }
            
            minutes++;
        }

        if(freshCount == 0) return minutes-1;
        return -1;
    }
};