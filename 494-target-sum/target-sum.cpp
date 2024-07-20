class Solution {
public:
    int helper(vector<int>& nums, int n, int t, unordered_map<string,int>& dp)
    {
        if(t == 0 && n == -1) return 1;
        if(n < 0) return 0;

        string key = to_string(n) + "," + to_string(t);

        if(dp.find(key) != dp.end()) return dp[key];

        int pos = helper(nums, n-1, t + nums[n], dp);
        int neg = helper(nums, n-1, t - nums[n], dp);

        return dp[key] = pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map <string, int> dp;
        int n = nums.size();
        return helper(nums, n-1, target, dp);
    }
};