class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(), 1);
        vector<int> hash(nums.size());

        int maxi = 1;
        int lastIndex = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++)
        {
            hash[i] = i;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i] )
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

        vector<int> temp;

        int index = lastIndex;
        while( index != hash[index])
        {
            temp.push_back(nums[index]);
            index = hash[index];
        }
        temp.push_back(nums[index]);
        reverse(temp.begin(), temp.end());
        return temp;
    }
};