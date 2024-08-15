class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            string odd = s.substr(l+1, r-l-1);
            if(odd.size() > ans.size()) ans = odd;

            l = i;r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            string even = s.substr(l+1, r-l-1);
            if(even.size() > ans.size()) ans = even;
        }

        return ans;
    }
};