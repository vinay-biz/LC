class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i=0; i<graph.size(); i++) //Because it's a forest
        {
            if(color[i] == -1) //Incase we haven't visited the node yet
            {
                queue<int> q;
                q.push(i); //Push the current node

                while(!q.empty()) //BFS
                {
                    int curr = q.front(); q.pop(); //Extract first element

                    for(auto vertex :graph[curr]) //Check it's neighbours
                    {
                        if(color[vertex] == -1)//If not visited, color it, then push it
                        {
                            color[vertex] = !color[curr];
                            q.push(vertex);
                        }
                        //if the node is already colored, check 
                        else if(color[vertex] == color[curr]) return false;
                    }
                }
            }
        }

        return true;
    }
};