class Solution {
public:
    int helper(int n, vector<int>& nums, int start, vector<int>& dp)
    {
        if(n < start) return 0;

        if(dp[n] != -1) return dp[n];

        int take = nums[n] + helper(n-2, nums, start, dp);
        int notTake = 0 + helper(n-1, nums, start, dp);

        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n,-1);
        int val1 = helper(n-2, nums, 0, dp);
        dp = vector<int> (n,-1);
        int val2 = helper(n-1, nums, 1, dp);
        return max(val1,val2);
    }
};