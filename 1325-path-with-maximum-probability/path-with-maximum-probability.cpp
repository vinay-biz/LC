class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<pair<int, double>>> adj(n); //First convert to an adjacency list

        for(int i = 0;  i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        vector<double> prob(n, 0);

        priority_queue<pair<double,int>> pq; //prob, node;
        pq.push({1, start_node});

        while(!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            for(auto node : adj[currNode]) {
                int adjNode = node.first;
                double adjProb = node.second;

                if(prob[adjNode] < currProb*adjProb) {
                    prob[adjNode] = currProb*adjProb;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }

        return prob[end_node];
    }
};