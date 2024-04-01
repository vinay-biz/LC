class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;

        for(int i=s.length()-1 ; i>=0; i--) //Lets find first character that is not a whitespace
        {
            if(s[i]==' ') continue;

            else
            {
                while(i>=0 && s[i] != ' ')
                {
                    length++;
                    i--;
                }
                break;
            }
        }
        return length;
    }
};