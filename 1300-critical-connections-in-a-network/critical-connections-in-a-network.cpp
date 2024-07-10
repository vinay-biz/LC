class Solution {
private :
    int timer = 1; //start the timer
public:
    void dfs(vector<vector<int>> &G, int node, int parent, vector<bool> &vis, 
                vector<int> &times, vector<int> &low, vector<vector<int>> &bridges)
    {
        vis[node] = true; //mark the node visited
        times[node] = timer; //set the timer
        low[node] = timer; //set the lowest time to reach
        timer++; //increase the timer

        for(auto adjNode : G[node])
        {
            if(adjNode == parent) continue;

            if(!vis[adjNode])
            {
                dfs(G,adjNode,node,vis,times,low,bridges);
                low[node] = min(low[node], low[adjNode]);
                
                if(low[adjNode] > times[node])
                {
                    bridges.push_back({node, adjNode});
                }
            }
            else
            {
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> G(n); //Create Adj List from edges

        for(int i=0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<bool> vis(n, false); //visited array
        vector<int> times(n); //Time of reaching a node
        vector<int> low(n); // Lowest time of reaching a node
        vector<vector<int>> bridges; //ans array
        
        dfs(G,0,0,vis,times,low,bridges); //Call dfs
        return bridges;
    }
};