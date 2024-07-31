class Solution {
public:
    bool check(vector<int>& nums) {
        int flag = false;
        for(int i=1; i<nums.size(); i++)
        {
            if(!flag)
            {
                if(nums[i] < nums[i-1]) flag = true;
            }
            else if(flag && nums[i] < nums[i-1]) return false;        
        }
        if(flag && nums[0] < nums[nums.size()-1]) return false;
        return true;
    }
};