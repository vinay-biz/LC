class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        long long chefTime = 0;
        long long TotalWaitTime = 0;

        for(int index = 0; index  < customers.size(); index++)
        {
            long long currTime = max(chefTime,(long long)customers[index][0]);
            chefTime = currTime + customers[index][1];
            TotalWaitTime += (chefTime- customers[index][0]);
            
        }

        double ans = ((double)TotalWaitTime) / ((double)customers.size());
        return ans;
    }
};