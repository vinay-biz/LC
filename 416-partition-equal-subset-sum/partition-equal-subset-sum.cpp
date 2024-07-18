class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); int sum = 0;
        if(n == 1) return false; 
        //If the array sum is odd, it cannot be divied into two equals
        for(int i=0; i<n; i++) sum += nums[i]; if(sum%2 == 1) return false; else sum = sum/2;
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));

        for(int i=0; i<n; i++) dp[i][0] = true; //Base case 1
        if(nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j) take = dp[i-1][j-nums[i]];

                dp[i][j] = (take ||notTake);
            }
        }

        return dp[n-1][sum];
    }
};