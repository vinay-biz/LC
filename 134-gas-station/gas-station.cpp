class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int fuelReq = 0; //To tell if we can ever reach
        int tank = 0; //To check where it becomes postitve, and dosen't go -ve again
        int start = 0;

        for(int i=0; i<gas.size(); i++)
        {   
            fuelReq += gas[i] - cost[i]; //Update current gas/req ratio
            tank += gas[i] - cost[i]; //Do the same
            if(tank < 0) //if ratio is neg, the next one might be the ans, not this one though
            {
                tank = 0;
                start = i+1;
            }
        }

        return (fuelReq<0)?-1:start;
    }
};