class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int index = 0;

        for(int i=0; i<g.size(); i++)
        {
            if(index >= s.size()) break;
            
            if(g[i] > s[index])
            {
                while( index < s.size() && g[i] > s[index]) index++;
            }

            if(index < s.size() && g[i] <= s[index]) 
            {
                ans++;
                index++;
            } 
        }

        return ans;
    }
};