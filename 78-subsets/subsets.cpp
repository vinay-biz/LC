class Solution {
public:
    void subsetFind(vector<int>& nums, vector<vector<int>>& res, vector<int>& currSubset,
                    int currIndex)
    {
        res.push_back(currSubset); //Add the current subset to ans

        for(int i=currIndex; i < nums.size(); i++)
        {
            //We include the current element in the subset
            currSubset.push_back(nums[i]);

            //Call subsetFind to add the new subset
            subsetFind(nums, res, currSubset, i+1);

            //BackTrack
            currSubset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currSubset;
        int currIndex = 0;
        
        subsetFind(nums, res, currSubset, currIndex);

        return res;
    }
};