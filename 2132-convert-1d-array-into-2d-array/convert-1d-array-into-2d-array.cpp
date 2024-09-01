class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(original.size() > m*n || original.size() < m*n) 
            return {};
    
        vector<vector<int>> ans(m, vector<int> (n));
        
        int x = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = original[x++];
        

        return ans;
    }
};