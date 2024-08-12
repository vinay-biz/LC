class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double ans = *max_element(nums.begin(), nums.end());

        double currMax = 1;
        double currMin = 1;

        for(auto n : nums)
        {
            double tmp = currMax*n;
            currMax = max(max(currMax * n, currMin * n), (double)n);
            currMin = min(min(tmp , currMin* n), (double)n);

            ans = max(ans, currMax);
        }

        return ans;
    }
};