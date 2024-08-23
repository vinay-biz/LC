class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, 0);

        for(int i = nums.size()-1; i >= 0; i--) {
            int take = nums[i] + dp[i+2];
            int notTake = dp[i+1];
            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};