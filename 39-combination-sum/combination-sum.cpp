class Solution {
public:
    void helper(vector<int>& nums, int sum, int i,vector<int>& curr, vector<vector<int>>& ans)
    {
        if(sum == 0)
        {
            ans.push_back(curr);
            return;
        }
        if(i == nums.size()) return;

        for(int idx = i; idx < nums.size(); ++idx)
        {
            if(sum >= nums[idx])
            {
                curr.push_back(nums[idx]);
                helper(nums, sum-nums[idx], idx, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int sum) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<int>> ans;
        vector<int> curr;

        helper(nums, sum, 0, curr, ans);
        return ans;
    }
};