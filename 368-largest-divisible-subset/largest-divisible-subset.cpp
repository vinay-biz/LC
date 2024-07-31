class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);

        sort(nums.begin(), nums.end());

        int maxi = 1;
        int lastIndex = 0;

        for(int i=0; i<n; i++)
        {
            hash[i] = i;
            for(int j=0; j<i; j++)
            {
                if((nums[i] % nums[j] == 0) && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        int index = lastIndex;

        while(hash[index] != index)
        {
            ans.push_back(nums[index]);
            index = hash[index];
        }

        ans.push_back(nums[index]);
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};