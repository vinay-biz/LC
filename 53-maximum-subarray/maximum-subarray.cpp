class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxi = INT_MIN;

        for(int i=0; i < nums.size(); i++)
        {
            currSum  = max(nums[i], currSum +nums[i]);

            maxi = max(maxi, currSum);
        }
        return maxi;
    }
};