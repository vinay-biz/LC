class Solution {
public:
    void helper(vector<int>& arr, int sum, int i, vector<int> curr, vector<vector<int>>& ans)
    {
        if(i == arr.size() || sum < 0) return;
        if(sum == 0) 
        {
            ans.push_back(curr);
            return;
        }

        helper(arr, sum , i+1, curr, ans);
        curr.push_back(arr[i]);
        helper(arr, sum - arr[i], i, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, curr, ans);
        return ans;
    }
};