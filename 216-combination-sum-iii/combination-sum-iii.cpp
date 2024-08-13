class Solution {
public:
    void helper(vector<int>& arr, int k , int sum, int i, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(sum == 0)
        {
            if(curr.size() == k) ans.push_back(curr);
            return;
        }

        for(int idx = i; idx < 9; idx++)
        {
            if(sum >= arr[idx])
            {
                curr.push_back(arr[idx]);
                helper(arr, k, sum-arr[idx], idx+1, curr, ans);
                curr.pop_back();
            }
        } 

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> curr;

        helper(v, k, n, 0, curr, ans);
        return ans;
    }
};