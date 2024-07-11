class Solution {
public:

    void subsetFind(vector<int> &nums, vector<vector<int>>& result, vector<int> subset,int index)
    {
        result.push_back(subset); //push the current subset

        for(int i=index; i<nums.size(); i++)
        {
            //Take the element
            subset.push_back(nums[i]);

            //Call subsetFind
            subsetFind(nums,result,subset,i+1);

            //Backtrack
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset; //For storing subsets

        subsetFind(nums, result, subset, 0);
        return result;
    }
};