class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> st; //(,index

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(') st.push(i);

            else if(s[i] == ')' && !st.empty()) st.pop();

            else if(s[i] == ')' && st.empty())
            {
                i--;
                s.erase(i+1,1);
            }
        }

        while(!st.empty())
        {
            int temp= st.top();
            st.pop();
            s.erase(temp,1);
        }

        return s;
    }
};