class Solution {
public:
    int helper(vector<int>& nums, int n, int sum, vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            if(sum == 0 && nums[0] == 0) return 2;
            if(sum == 0 ||sum == nums[0]) return 1;
            return 0;
        }

        if(dp[n][sum] != -1) return dp[n][sum];

        int notTake = helper(nums, n-1, sum, dp);
        int take = 0;
        if(nums[n] <= sum) take = helper(nums, n-1, sum-nums[n], dp);

        return dp[n][sum] = take + notTake; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0; for(int i=0; i<n; i++) totSum += nums[i];

        int sum;
        if((totSum - target)%2 != 0) return 0;
         
        if(totSum-target >= 0) sum = (totSum - target)/2;
        else return 0;

        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return helper(nums, n-1, sum, dp);
    }
    /*
        s1 - s2 = target
        totSum - s2 - s2 = target
        totalSum - 2*s2 = target
        (totalSum - target) / 2 = s2
    */
};