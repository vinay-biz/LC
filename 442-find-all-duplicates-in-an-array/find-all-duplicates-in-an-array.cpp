class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) nums[i] = -nums[i];

        for(int i=0; i<nums.size(); i++)
        {
            int x = abs(nums[i]);

            if(x == nums.size()) nums[0] = abs(nums[0]);

            else nums[x] = abs(nums[x]);
        }

        for(int i=0; i<nums.size(); i++)
        {
            int x = abs(nums[i]);

            if(x == nums.size()) nums[0] = -nums[0];

            else nums[x] = -nums[x];
        }

        if(nums[0] > 0) ans.push_back(nums.size());

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > 0) ans.push_back(i);
        }

        return ans;
    }
};