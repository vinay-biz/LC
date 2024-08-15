class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int count5 = 0;
        int count10 = 0;
        int count20 = 0;

        for(auto bill : bills) {
            if(bill == 5) count5++;

            else if(bill == 10 && count5 > 0)
            {
                count10++;
                count5--;
            } 

            else if(bill == 20 && ((count5 > 0 && count10 > 0) || count5 > 2))
            {
                count20++;

                if(count10 > 0)
                {
                    count10--;
                    count5--;
                }

                else count5 -= 3;
            }

            else return false;
        }

        return true;
    }
};