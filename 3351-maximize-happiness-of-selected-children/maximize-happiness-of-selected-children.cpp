class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


        sort(happiness.begin(),happiness.end(),greater<int>());
        int i=0;
        long long ans = 0;

        while(k--)
        {
            happiness[i] = max(happiness[i]-i,0);
            ans += happiness[i];
            i++;
        }

        return ans;
         
    }
};