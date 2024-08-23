class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = 0, ahead = 0, ahead2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            curr = max(nums[i] + ahead2, ahead);

            ahead2 = ahead;
            ahead = curr;
        }

        return ahead;
    }
};