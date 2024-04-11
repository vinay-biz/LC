class Solution {
public:
    string removeKdigits(string num, int k) {
        //Intution we need to make sure that the number ahead is smaller than the number ahead
        //If not pop the number behind
        //If the whole is in increasing order 
        //Pop from th estack to suffice k

        stack<char> st;
        for(int i=0; i<num.length(); i++)
        {
            while(k>0 && !st.empty() && st.top() > num[i])
            {
                k--;
                st.pop();
            }
            st.push(num[i]);//ultimately we are gonna add the character to the stack
        }

        while(k>0) //incase some characters to be removed are at end;
        {
            st.pop();
            k--;
        }

        //convert stack to string
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end()); //reverse it to get original
        for(int i=0; i<ans.length(); i++) //check for trailing whitespaces
        {
            if(ans[i] != '0') break;
            else
            {
                ans.erase(i,1);
                i--;
            }
        }

        if(ans == "") return "0"; //dumb edge case
        return ans;
    }
};