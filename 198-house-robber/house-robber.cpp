class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = 0, ahead = 0, ahead2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            int take = nums[i] + ahead2;
            int notTake = ahead;
            curr = max(take, notTake);

            ahead2 = ahead;
            ahead = curr;
        }

        return ahead;
    }
};