class Solution {
public:
    void helper(vector<int>& nums, int sum, int i, vector<int>& cur, vector<vector<int>>& ans)
    {
        if(sum == 0){
            ans.push_back(cur);
            return;
        }

        if(i == nums.size()) return;

        for(int x = i; x < nums.size(); ++x){
            if(x > i && nums[x] == nums[x-1]) continue;
            if(sum >= nums[x]){
                cur.push_back(nums[x]);
                helper(nums, sum-nums[x], x+1, cur, ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        helper(nums, sum, 0, cur, ans);
        return ans;
    }
};