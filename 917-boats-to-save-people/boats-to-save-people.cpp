const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:

    
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int left=0, right=people.size()-1;

        while(left<=right)
        {
            if(people[left]+people[right] <= limit)
            {
                left++;
                right--;
                ans++;
            }

            else 
            {
                right--;
                ans++;
            }
        }

        return ans;
    }
};