class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); if(n == 0) return 0; if(n == 1) return nums[0];
        vector<int> dp(n,-1); int take,notTake;

        int val1, val2, curr, prev2 = 0, prev = nums[0];
        
        for(int i=1; i<n-1; i++)
        {
            take =  nums[i]; if(i >= 2) take += prev2;
            notTake = 0 + prev;
            curr = max(take, notTake);

            prev2 = prev; prev = curr;
        } val1 = prev;

        prev2 = 0; prev = nums[1];

        for(int i=2; i<n; i++)
        {
            take = nums[i]; if(i >= 3) take += prev2;
            notTake = 0 + prev;

            curr = max(take, notTake);

            prev2 = prev; prev = curr;
        }val2 = prev;
        
        return max(val1,val2);
    }
};