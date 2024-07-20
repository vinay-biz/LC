class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n = g.size(), m = s.size(), i = 0, j = 0, ans = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i < n && j < m)
        {
            if(g[i] <= s[j])
            {
                ans++;
                i++;
            }

            j++;
        }

        return ans;
    }
};