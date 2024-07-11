class Solution {
public:
    void permute(vector<int> &nums, vector<vector<int>> &ans, int left, int right)
    {
        if(left == right) ans.push_back(nums); //Permutation Complete

        else //Swap each character with every other one and fix it
        {
            for(int i=left; i<=right; i++)
            {
                //Perform swap
                swap(nums[left],nums[i]);

                //Recursive call to permuation fixing left
                permute(nums,ans,left+1,right);

                //Backtrack
                swap(nums[left],nums[i]); 

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        permute(nums,ans,0,nums.size()-1);
        return ans;
    }
};