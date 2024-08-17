class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();

        vector<long long> prev(n, 0), curr(n, 0);
        for(int i=0; i<n; i++) prev[i] = points[0][i];

        for(int row=1; row<m; row++)
        {
            vector<long long> leftMax(n, 0);
            vector<long long> rightMax(n, 0);

            leftMax[0] = prev[0];
            for(int i=1; i<n; i++) leftMax[i] = max(leftMax[i-1]-1, prev[i]);

            rightMax[n-1] = prev[n-1];
            for(int i=n-2; i>=0; i--) rightMax[i] = max(rightMax[i+1]-1, prev[i]);

            for(int i=0; i<n; i++)
                curr[i] = max(leftMax[i], rightMax[i]) + points[row][i];

            prev = curr;
        }

        long long ans = INT_MIN; 
        for(int i=0; i<n; i++)
            ans = max(ans, prev[i]);

        return ans;
    }
};