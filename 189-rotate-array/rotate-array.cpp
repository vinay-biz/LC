class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,0);

        for(int i=0; i<n; i++)
        {
            int newIndex = (i + k)%n;
            ans[newIndex] = nums[i];
        }

        nums = ans;
    }
};