class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<bool> vis(10, false);

        for(int i = 0; i < n - 2; i++) {     //Go over the array
            for(int j = 0; j < m - 2; j++) {
                
                bool flag = false;
                int row0 = 0, row1 = 0, row2 = 0, col0 = 0, col1 = 0, col2 = 0,daigr = 0,daigl = 0;

                for(int x = i; x < i + 3; x++) {
                    for(int y = j; y < j+3; y++) {
                        if(grid[x][y] > 9 || grid[x][y] < 1 || vis[grid[x][y]] == true) {
                            flag = true;
                            break;
                        }

                        else vis[grid[x][y]] = true;

                        int xi = x - i, yj = y - j;
                        if(xi == 0) row0 += grid[x][y];
                        if(xi == 1) row1 += grid[x][y];
                        if(xi == 2) row2 += grid[x][y];

                        if(yj == 0) col0 += grid[x][y];
                        if(yj == 1) col1 += grid[x][y];
                        if(yj == 2) col2 += grid[x][y];
                    
                        if(xi == yj) daigr += grid[x][y];
                        if((xi == 0 && yj == 2) || (xi == 1 && yj == 1) || (xi == 2 && yj == 0))
                        daigl += grid[x][y];
                    }
                    if(flag) break;
                }

                if(!flag && row0 == row1 && row1 == row2 && row2 == col0 && col0 == col1 && col1 == col2 
                   && col2 == daigl && daigl == daigr ) ans++;

                vis = vector<bool> (10, false);

            }
        }

        return ans;
    }
};
// 00  01  02  
// 10  11  12
// 20  21  22