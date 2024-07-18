class Solution {
public:
    bool helper(vector<int>& nums, int n, int target, vector<vector<int>>& dp)
    {
        if(target == 0) return true;
        if(n == 0) return (nums[0] == target);

        if(dp[n][target] != -1) return dp[n][target];

        bool notTake = helper(nums, n-1, target,dp);
        bool take = false;
        if(target >= nums[n]) take = helper(nums, n-1, target - nums[n],dp);

        return dp[n][target] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0; for(int i=0; i<n; i++) target += nums[i];

        if(target%2 == 1) return false;
        else target = target/2;

        vector<vector<int>> dp(n, vector<int> (target+1, -1));

        return helper(nums, n-1, target, dp);
    }
};