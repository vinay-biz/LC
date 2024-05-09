class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;

        priority_queue<int> pq;

        for(auto x : happiness) pq.push(x);
        int cnt = 0;

        while(!pq.empty())
        {
            if(cnt >= k) break;
            int n = pq.top();
            pq.pop();

            n -= cnt;
            if(n > 0) ans += n;
            cnt++;
        }

        return ans;
         
    }
};