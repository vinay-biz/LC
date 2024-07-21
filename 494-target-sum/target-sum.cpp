class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0,n = nums.size(); 
        
        for(int i=0; i<n; i++) 
        totSum += nums[i];
        
        int val = totSum - target;
        
        if((val)%2 != 0 || val < 0) return 0; 
        int sum = val/2; 
        
        vector<vector<int>> dp(n, vector<int> (sum+1, 0));
        if(nums[0] == 0) dp[0][0] = 2; else dp[0][0] = 1;
        //for(int i=0; i<n; i++) dp[i][0] = 1;
        if( nums[0] != 0 && nums[0] <= sum) dp[0][nums[0]] = 1;

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                int notTake = dp[i-1][j];
                int take = 0;
                if(nums[i] <= j) take = dp[i-1][j-nums[i]];

                dp[i][j] = take + notTake;
            }
        }




        return dp[n-1][sum];
    }
    /*
        s1 - s2 = target
        totSum - s2 - s2 = target
        totalSum - 2*s2 = target
        (totalSum - target) / 2 = s2
    */
};