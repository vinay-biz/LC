class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> starSt;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(') st.push(i);
            else if(s[i] == '*') starSt.push(i);

            else if(s[i] == ')')
            {
                if(!st.empty()) st.pop();

                else if(!starSt.empty()) starSt.pop();

                else return false;
            }
        }

        while(!st.empty() && !starSt.empty())
        {
            if(st.top() > starSt.top()) return false;

            st.pop(); starSt.pop();
        }

        return st.empty();
    }
};