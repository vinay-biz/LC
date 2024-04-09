class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for(int i=0; i<tickets.size(); i++)
        {
            if(i == k) continue; // skip the actual tickets count

            if(tickets[i]<tickets[k]) ans += tickets[i]; //we will def buy all tickets

            if(tickets[i]>=tickets[k] && i>k) ans += tickets[k] - 1; //we will only buy tickets till k is not zero so k-1

            if(tickets[i]>=tickets[k] && i<k) ans+= tickets[k];//we will def buy k tickets
        }

        ans+= tickets[k];
        return ans;
    }
};