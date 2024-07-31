class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        int ans = 1;

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > arr.back()) arr.push_back(nums[i]);

            else 
            {
                int index = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
                arr[index] = nums[i];
            }
        }

        return arr.size();
    }
};