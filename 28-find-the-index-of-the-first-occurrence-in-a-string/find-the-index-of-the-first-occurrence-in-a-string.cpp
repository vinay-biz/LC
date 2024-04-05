class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        unordered_set <string> s; //Create hash structure
        s.insert(needle); //insert he needle to find in hash

        string temp = "";
        for(int i=0; i<=(haystack.length() - needle.length()) ; i++) //sliding window for needle length
        {
            temp = haystack.substr(i,needle.length()); //extract needle length substring
            if(s.find(temp)!=s.end()) return i; //if present return it
        }

        return -1;
    }
};