class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        int j = 0 , k = nums.size()-1, sum  = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0) break;

            if(i > 0 &&  nums[i-1] == nums[i]) continue;

            j = i+1;
            k = nums.size() - 1;
            sum = 0;

            while(j < k)
            {
                sum = nums[i] + nums[j] + nums[k];

                if(sum > 0) k--;
                else if(sum < 0) j++;
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int x = nums[j];
                    int y = nums[k];
                    while(j<k && nums[j]==x)j++;
                    x = nums[k];
                    while(j<k && nums[k]==x)k--;
                }
            }    
            
        }

        return ans;
    }
};