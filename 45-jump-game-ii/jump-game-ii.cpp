class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if(i >= n) return 1e9;

        if(i == n-1) return 0;

        if(dp[i] != -1) return dp[i];
    
        int jump = 1e9;
        for(int j = 1; j <= nums[i]; ++j){
            if(i + j < n){
                int temp = 1 + helper(nums, i+j, dp);
                jump = min(jump, temp);
            }
        }

        return dp[i] = jump;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size()+1, 1);
        dp[n] = 1e9; dp[n-1] = 0;

        for(int i = n-2; i  >= 0; --i) {
            int jump = 1e9;
            for(int j = 1; j <= nums[i]; ++j) {
                if(i + j < n){
                    int temp = 1 + dp[i+j];
                    jump = min(temp, jump);
                }
            }
            dp[i] = jump;
        }
        return dp[0];
    }
};