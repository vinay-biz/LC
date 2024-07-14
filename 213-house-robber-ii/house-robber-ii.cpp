class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); if(n == 0) return 0; if(n == 1) return nums[0];
        vector<int> dp(n,-1); int take,notTake;

        dp[0] = nums[0];
        
        for(int i=1; i<n-1; i++)
        {
            take =  nums[i]; if(i >= 2) take += dp[i-2];
            notTake = 0 + dp[i-1];

            dp[i] = max(take, notTake);
        }
        int val1 = dp[n-2];

        dp = vector<int> (n,-1);
    
        dp[1] = nums[1];

        for(int i=2; i<n; i++)
        {
            take = nums[i]; if(i >= 3) take += dp[i-2];
            notTake = 0 + dp[i-1];

            dp[i] = max(take, notTake);
        }
        int val2 = dp[n-1];
        
        return max(val1,val2);
    }
};