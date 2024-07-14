class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int prev = nums[0];
        int prev2, curr;

        int take, notTake;
        for(int i = 1; i < n; i++)
        {
            take = nums[i];
            if(i > 1) take += prev2;
            notTake = 0 + prev;

            curr = max(take , notTake);

            prev2 = prev;
            prev = curr;

        }
        return prev;
    }
};