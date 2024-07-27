class Solution {
public:
    int helper(vector<int>& nums, int n, int prev, vector<vector<int>>& dp)
    {
        if(n == nums.size()) return 0;

        if(dp[n][prev+1] != -1) return dp[n][prev+1];

        int skip = 0 + helper(nums, n+1, prev, dp);
        if(prev == -1 || nums[n] > nums[prev]) skip = max (skip, 1 + helper(nums, n+1, n, dp));

        return dp[n][prev+1] = skip;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return helper(nums, 0, -1, dp);
    }
};