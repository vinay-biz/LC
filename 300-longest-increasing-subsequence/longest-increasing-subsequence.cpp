class Solution {
public:
    int helper(vector<int>& nums, int n, int prev, vector<vector<int>>& dp)
    {
        if(n < 0) return 0;

        if(dp[n][prev+1] != -1) return dp[n][prev+1];

        int skip = helper(nums, n-1, prev, dp);
        if(prev == -1||nums[n] < nums[prev] )   
            return dp[n][prev+1] = max(1 + helper(nums, n-1, n, dp), skip);
        
        return dp[n][prev+1] = skip;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return helper(nums, nums.size()-1, -1, dp);
    }
};