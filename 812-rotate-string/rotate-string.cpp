class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false; //Two string can not be rotated then

        string ans = s + s;

        if(ans.find(goal) == -1) return false;
        return true;
    }
};