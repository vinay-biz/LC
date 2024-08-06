#define INF 1e9
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<vector<int>>> graph(n); //create a adj list out of the edges

        for(int i=0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            graph[u].push_back({v,w});
        }

        vector<int> dist(n,INF); //distance array
        queue <vector<int>> pq; //wt, node, k    

        pq.push({0 ,src, 0});
        dist[src] = 0; //distance of src from itself is 0

        while(!pq.empty())
        {
            vector<int> it = pq.front();

            int currDist = it[0];
            int node = it[1];
            int kVal = it[2];
             
            pq.pop();

            if(kVal > k) continue;

            for(auto adj : graph[node])
            {
                int adjNode = adj[0];
                int adjDist = adj[1];

                if((currDist + adjDist) < dist[adjNode]) //incase we found a better route
                {
                    dist[adjNode] = currDist + adjDist;
                    pq.push({dist[adjNode], adjNode, kVal + 1});
                }
            }
        }

        if(dist[dst] == INF) return -1;
        return dist[dst];
        }
};