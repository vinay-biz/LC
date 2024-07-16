class Solution {
public:
   int minFallingPathSum(vector<vector<int>>& matrix) {
    std::ios_base::sync_with_stdio(false);std::cout.tie(nullptr);std::cin.tie(nullptr);
        int n = matrix.size(); int ans = 1e9;
        vector<int> prev(n,0), curr(n,0);

        for(int i=0; i<n; i++) prev[i] = matrix[0][i];

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + prev[j];

                int left = matrix[i][j];
                if(j > 0) left += prev[j-1];
                else left += 1e9;

                int right = matrix[i][j];
                if(j < n - 1) right +=  prev[j+1];
                else right += 1e9;

                curr[j] = min(min(left,right),up);
            }
            prev = curr;
        }

        for(int i=0; i<n; i++) ans = min(ans, prev[i]);
        return ans;
    }
};