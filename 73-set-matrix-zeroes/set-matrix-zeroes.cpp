class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int col0 = 1;

        //Set the boundary
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    
                    matrix[i][0] = 0; //Boundary element marked
                    if(j != 0) matrix[0][j] = 0; //Boundary element marked
                    else col0 = 0;
                }
            }
        }

        //Set 0th row and column
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
                
            }
        }

        if(matrix[0][0] == 0) for(int i=0; i<matrix[0].size(); i++) matrix[0][i] = 0;
        if(col0 == 0) for(int i=0; i<matrix.size(); i++) matrix[i][0] = 0;

    }
};