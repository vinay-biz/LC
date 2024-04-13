class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false; //Two string can not be rotated then

        for(int i = 0;i <= s.size(); i++) //<= , if not, the condition of s == goal or last permu will be skipped 
        {
            s = s + s[0]; //add first element to back
            s.erase(0,1); //remove first element
            if(s==goal) return true; //check
        }

        return false;
    }
};