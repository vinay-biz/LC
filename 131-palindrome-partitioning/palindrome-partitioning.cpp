class Solution {
public:
    bool check(string s) {
        int left = 0, right = s.length()-1;
        while(left <= right) {
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }

    void helper(string s, int i, vector<vector<string>>& ans, vector<string> curr) {
        if(i == s.size())
        {
            ans.push_back(curr);
            return;
        }

        string str = "";
        for(int j = i; j < s.size(); j++){
            str += s[j];
            if(check(str))
            {
                curr.push_back(str);
                helper(s, j+1, ans, curr);
                curr.pop_back();
            }
        }     
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        helper(s, 0, ans, temp);
        return ans;
    }
};