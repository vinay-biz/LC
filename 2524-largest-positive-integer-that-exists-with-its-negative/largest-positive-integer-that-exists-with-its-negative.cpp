class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int mx = -1;

        unordered_set <int> st;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0 && st.find(-(nums[i]))!=st.end() || nums[i] < 0 && st.find(abs(nums[i]))!=st.end())
            {
                mx = max(mx , abs(nums[i]));
            } 

            else 
            {
                st.insert(nums[i]);
            }
        }

        return mx;
    }
};