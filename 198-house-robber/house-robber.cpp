class Solution {
public:
    int helper(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int take = helper(nums, n-2, dp) + nums[n];
        int notTake = helper(nums, n-1, dp) + 0;

        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, nums.size()-1, dp);
    }
};