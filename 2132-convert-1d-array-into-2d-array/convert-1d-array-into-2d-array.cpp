class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        vector<vector<int>> ans;

        if(sz > m*n || sz < m*n) 
            return ans;
        
        ans = vector<vector<int>> (m, vector<int> (n));
        int x = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = original[x++];
            }
        }

        return ans;
    }
};