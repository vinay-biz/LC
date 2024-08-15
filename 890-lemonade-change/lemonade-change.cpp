class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3, 0);

        for(int i=0; i<bills.size(); i++) {
            if(bills[i] == 5) change[0]++;

            else if(bills[i] == 10 && change[0] > 0)
            {
                change[1]++;
                change[0]--;
            } 

            else if(bills[i] == 20 && ((change[0] > 0 && change[1] > 0) || change[0] > 2))
            {
                change[2]++;

                if(change[1] > 0)
                {
                    change[1]--;
                    change[0]--;
                }

                else change[0] -= 3;
            }

            else return false;
        }

        return true;
    }
};