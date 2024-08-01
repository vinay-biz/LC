class Solution {
public:
    bool cmp(string& next, string& prev)
    {
        if(next.size() !=  1+prev.size()) return false;

        int nextPtr = 0;
        int prevPtr = 0;

        int count = 0;

        while(nextPtr < next.size())
        {
            if(next[nextPtr] != prev[prevPtr]) nextPtr++;
            
            else
            {
                nextPtr++;
                prevPtr++;
            }
        }

        if(nextPtr == next.size() && prevPtr == prev.size()) return true;
        return false;
    }
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n = words.size();
        vector<int> dp(n,1);
        int ans = 1;

        sort(words.begin(), words.end(), comp);

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(cmp(words[i], words[j]) && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i] > ans) ans = dp[i];
        }

        return ans;
    }
};