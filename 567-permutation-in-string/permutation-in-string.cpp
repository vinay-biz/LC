class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0, right=0; //set left and right pointer
        unordered_map <char,int> mp;

        for(int i=0; i<s1.size(); i++) mp[s1[i]]++;

        while(left < s2.size() && right < s2.size())
        {
            if(mp.find(s2[right])==mp.end()) //incase the element is not a part
            {
                while(left < right) //make the hashmap right again
                {
                    mp[s2[left]]++;
                    left++;
                }
                left = right + 1;
                right = right + 1;
            }

            else //incase element is a part 
            {
                if(mp[s2[right]] > 0) //if we haven't gone to minus value yet
                {
                    mp[s2[right]]--;
                    if((right-left+1) == s1.length()) return true; //maybe we're just done
                    right++; //otherwise next element please
                }

                if(mp[s2[right]] == 0) //incase the values are gonna go to negitive
                {
                    while(mp[s2[right]] == 0) //lets reduce left till it can be poititve again
                    {
                        mp[s2[left]]++;
                        left++;
                    } //remember no shifting right yet, we have to still check the new string
                }
            }
        }

        return false; //No luck :(


    }
};