class Solution {
public:
    string expand(int i, int j, string s)
    {
        int left = i;
        int right = j;

        while(left >=0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            string odd = expand(i, i, s);
            if(odd.size() > ans.size()) ans = odd;

            string even = expand(i, i+1, s);
            if(even.size() > ans.size()) ans = even;
        }

        return ans;
    }
};