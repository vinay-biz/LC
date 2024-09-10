class Solution {
public:
    int helper(vector<int>& nums,int& n, int i, vector<int>& dp) {
        if(i >= n) return 1e9;

        if(i == n-1) return 0;

        if(dp[i] != -1) return dp[i];
    
        int jump = 1e9;
        for(int j = 1; j <= nums[i]; ++j){
            if(i + j < n){
                int temp = 1 + helper(nums,n, i+j, dp);
                jump = min(jump, temp);
            }
        }

        return dp[i] = jump;
    }
    int jump(vector<int>& nums) {
        int n =  nums.size();
        vector<int> dp(n, -1);
        return helper(nums,n, 0, dp);
    }
};