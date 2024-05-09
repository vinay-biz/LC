class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        int cnt = 0;
        long long ans = 0;

        for(auto x : happiness) pq.push(x);
        
        for(int i=0; i<k; i++)
        {
            ans += max(0,(pq.top()-cnt));
            pq.pop();
            cnt++;
        }

        return ans;
         
    }
};