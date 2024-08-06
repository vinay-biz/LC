class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<pair<int,int>>adj[n];
        for(auto& it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int>dist(n, 1e9);
        
        // {stops, {node, dist}}
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        
        dist[src] = 0;
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int stops = p.first;
            int node = p.second.first;
            int dis = p.second.second;
            
            if(stops > K)
                break;
            
            
            for(auto& it : adj[node])
            {
                int adjNode = it.first;
                int cost = it.second;
                
                if(dis + cost < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = dis + cost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            
            }
        }
        
        
        if(dist[dst] == 1e9)
            return -1;
        
        return dist[dst];
    }
};