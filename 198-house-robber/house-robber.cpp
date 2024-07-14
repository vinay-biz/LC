class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; //edge case
        vector<int> dp(n,0);
        
        dp[0] = nums[0];
        dp[1] = nums[1];

        int left, right;
        for(int i=2; i<n; i++)
        {   
            left = (i >= 2) ? dp[i-2] : 0;
            right = (i >= 3) ? dp[i-3] : 0;

            dp[i] = max(left, right) + nums[i];
        }

        return max(dp[n-1], dp[n-2]);
    }
};