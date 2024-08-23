class Solution {
public:
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+2, 0);
        int curr = 0, ahead = 0, ahead2 = 0;

        for(int i = nums.size()-1; i >= 0; i--) {
            int take = nums[i] + ahead2;
            int notTake = ahead;
            curr = max(take, notTake);

            ahead2 = ahead;
            ahead = curr;
        }

        return ahead;
    }
};