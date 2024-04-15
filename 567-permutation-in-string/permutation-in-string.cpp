class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0, right=0;
        unordered_map <char,int> mp,backup;

        for(int i=0; i<s1.size(); i++) 
        {
            mp[s1[i]]++;
            backup[s1[i]]++;
        }

        while(left < s2.size() && right < s2.size())
        {
            if(mp.find(s2[right])==mp.end()) //incase the element is not a part
            {
                left = right + 1;
                right = right + 1;
                mp = backup;
            }

            else
            {
                if(mp[s2[right]] > 0)
                {
                    mp[s2[right]]--;
                    if((right-left+1) == s1.length()) return true;
                    right++;
                }

                if(mp[s2[right]] == 0)
                {
                    while(mp[s2[right]] == 0)
                    {
                        mp[s2[left]]++;
                        left++;
                    }
                }
            }
        }

        return false;


    }
};