class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp)
    {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int take = nums[i] + helper(nums, i+2, dp);
        int notTake = 0 + helper(nums, i+1, dp);

        return dp[i] =  max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};