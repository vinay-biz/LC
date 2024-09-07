class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<long long>>> adj(n);

        for(int i = 0; i < roads.size(); i++){
            long long u = (long long)roads[i][0];
            long long v = (long long)roads[i][1];
            long long w = (long long)roads[i][2];

            adj[u].push_back({(long long)v, (long long)w});
            adj[v].push_back({(long long)u, (long long)w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> reach(n, 0);
        priority_queue <pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0, 0}); //dist, node
        dist[0] = (long long)0;
        reach[0] = (long long)1;
        const int mod = 1e9 + 7;

        while(!pq.empty()) {
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for(auto x : adj[node]) {
                long long adjNode = x[0];
                long long adjDis = x[1];

                if(dist[adjNode] > dis + adjDis) {
                    dist[adjNode] = dis + adjDis;
                    reach[adjNode] = reach[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(dist[adjNode] == dis + adjDis) {
                    reach[adjNode] = ((reach[adjNode])%mod + (reach[node])%mod)%mod;
                }
            }
        }

        return (int)reach[n-1];
    }
};