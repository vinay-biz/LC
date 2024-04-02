class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<bool> check  (256,false);
        unordered_map <char,char> mp;

        for(int i=0; i<s.length(); i++)
        {
            if(mp.find(s[i]) == mp.end() && !check[t[i]]) 
            
            {
                mp[s[i]] = t[i];
                check[t[i]] = true;
            }

            else
            {
                if(mp[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};