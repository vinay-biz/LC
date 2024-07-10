    class Solution {
    public:

        void dfs(int node, int parent, vector<vector<int>> &G, vector<bool> &vis, 
                vector<int> &times, vector<int> &low, vector<vector<int>> &bridges, 
                int &time)
        {
            vis[node] = true; //visit the node
            times[node] = time; //set it's time of arrival
            low[node] = time; //also set lowest time of arrival
            time++; //increment time

            for(auto adjNode : G[node])
            {
                if(adjNode == parent) continue; //do nothing if it is the parent

                if(!vis[adjNode]) //if we have not visited the node
                {
                    dfs(adjNode,node,G,vis,times,low,bridges,time); //dfs it
                    low[node] = min(low[node], low[adjNode]); //Set the lowest time

                    //if the lowest time to visit the adjNode is greater than
                    //time of visit of current node, then it is bridge
                    if(low[adjNode] > times[node]) bridges.push_back({node,adjNode});
                }
                else
                {
                    //If it is visited, just update the low
                    low[node] = min(low[node], low[adjNode]);
                }
            }
        }
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            //Connections is an edge list
            //Lets convert it to adj List

            vector<vector<int>> G(n);
            for(auto x : connections)
            {
                G[x[0]].push_back(x[1]);
                G[x[1]].push_back(x[0]);
            }

            vector<bool> vis(n,false); //vis array
            vector<int> times(n); //Time of processing of node in DFS
            vector<int> low(n); //lowest time of adj nodes expect parent
            vector<vector<int>> bridges; //critical connections or bridges in a graph
            int time = 1;//current time

            dfs(0,0,G,vis,times,low,bridges,time);
            return bridges;
        }
    };