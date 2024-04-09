class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for(int i=0; i<tickets.size(); i++)
        {
            if(i == k) ans+= tickets[k]; // skip the actual tickets count

            else if(tickets[i]<tickets[k]) ans += tickets[i]; //we will def buy all tickets

            else if(tickets[i]>=tickets[k] && i>k) ans += tickets[k] - 1; //we will only buy tickets till k is not zero so k-1

            else if(tickets[i]>=tickets[k] && i<k) ans+= tickets[k];//we will def buy k tickets
        }
        return ans;
    }
};