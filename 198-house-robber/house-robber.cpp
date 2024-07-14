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
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];

        int take, notTake;
        for(int i = 1; i < n; i++)
        {
            take = nums[i];
            if(i > 1) take += dp[i-2];
            notTake = 0 + dp[i-1];

            dp[i] = max(take , notTake); 
        }
        return dp[n-1];
    }
};