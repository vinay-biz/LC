class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        //Initialise the maps;
        for(int i=0; i<s1.length(); i++) 
        {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }

        //Matintain match count
        int match = 0;
        for(int i = 0; i<26; i++)
        {
            if(mp1[i] == mp2[i] ) match++;
        }

        int left = 0;
        //Sliding Window
        for(int right = n; right < m; right++)
        {
            if(match == 26) return true;

            int index = s2[right] - 'a'; //Which is the next character to include

            //Include the next character
            mp2[index]++;
            if(mp1[index] == mp2[index]) match++; //If by increasing the count becomes equal
            else if(mp1[index]+1 == mp2[index]) //If including the charcter exceed count
            match--;

            //Remove the left charcter

            index = s2[left] - 'a'; //Which is the character to remove

            //Remove the last character
            mp2[index]--;
            if(mp1[index] == mp2[index]) match++; //If by decreasing the count becomes equal
            else if(mp1[index]-1 == mp2[index]) //If removing, the charcter dimineshes count
            match--;
            left++;
        }

        return (match == 26);
    }
};