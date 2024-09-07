class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<pair<int, long long>>> adj(n);  // Using pair instead of vector<vector<long long>>

        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            long long w = (long long)roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> reach(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); //dist, node
        dist[0] = 0;
        reach[0] = 1;
        const int mod = 1e9 + 7;

        while(!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;  // Skip outdated distances

            for(auto& [adjNode, adjDis] : adj[node]) {
                if (dist[adjNode] > dis + adjDis) {
                    dist[adjNode] = dis + adjDis;
                    reach[adjNode] = reach[node];
                    pq.push({dist[adjNode], adjNode});
                } 
                else if (dist[adjNode] == dis + adjDis) {
                    reach[adjNode] = (reach[adjNode] + reach[node]) % mod;  // Fewer modulo operations
                }
            }
        }

        return (int)reach[n-1];
    }
};
