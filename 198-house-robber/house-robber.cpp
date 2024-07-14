class Solution {
public:
    int helper(vector<int>& nums, int n, vector<int> &dp)
    {
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int left, right;
        left = helper(nums, n-2,dp) + nums[n]; 
        right = helper(nums, n-3, dp) + nums[n];

        return dp[n] = max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);

        int left = helper(nums,n,dp);
        int right = helper(nums, n-1,dp);

        return max(left,right);
    }
};