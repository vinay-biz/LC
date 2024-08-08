class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int r = rStart; //current row
        int c = cStart; //current col

        int x[] = {0, 1, 0, -1}; //R,D,L,U
        int y[] = {1, 0, -1, 0}; 

        int i = 0;

        int steps = 1; //have to increase by one after every two sides
        while(ans.size() < (rows * cols))
        {
            for(int z = 0; z < 2; z++)
            {
                for(int j = 0; j < steps; j++)
                {
                    if(r >= 0 && c >=0 && r < rows && c < cols)
                    ans.push_back({r,c});

                    r = r + x[i];
                    c = c + y[i];
                }
                
                i = (i + 1) % 4;
            }
            
            steps += 1;
        }

        return ans;
    }
};