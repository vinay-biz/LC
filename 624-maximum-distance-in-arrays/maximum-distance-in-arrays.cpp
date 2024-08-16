class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mn = arr[0][0];
        int mx = arr[0].back();
        int ans = 0;

        for(int i = 1; i < arr.size(); i++)
        {
            ans = max(ans, abs(arr[i].back() - mn));
            ans = max(ans, abs(mx - arr[i][0]));
            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i].back());
        }
        return ans;
    }
};