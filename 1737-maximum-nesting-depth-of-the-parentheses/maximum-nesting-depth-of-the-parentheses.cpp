class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxD = 0;

        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]=='(') depth++;
            else if(s[i]==')') depth--;

            maxD = max(maxD,depth);
        }
        return maxD;
    }
};