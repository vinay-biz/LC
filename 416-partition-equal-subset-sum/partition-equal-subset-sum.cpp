class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); int sum = 0;
        
        for(int i=0; i<n; i++) sum += nums[i]; if(sum%2 == 1) return false; else sum = sum/2;
        //vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        prev[0] = curr[0] =  true; //Base case 1
        if(nums[0] <= sum) prev[nums[0]] = true; //Base case 2

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                bool notTake = prev[j];
                bool take = false;
                if(nums[i] <= j) take = prev[j-nums[i]];

                curr[j] = (take ||notTake);
            }
            prev = curr;
        }

        return prev[sum];
    }
};