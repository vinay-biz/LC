class Solution {
public:
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