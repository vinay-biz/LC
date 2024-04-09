class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for(int i=0; i<tickets.size(); i++)
        {
            if(i == k) continue;

            if(tickets[i]<tickets[k]) ans += tickets[i];

            if(tickets[i]>=tickets[k] && i>k) ans += tickets[k] - 1;

            if(tickets[i]>=tickets[k] && i<k) ans+= tickets[k];
        }

        ans+= tickets[k];
        return ans;
    }
};