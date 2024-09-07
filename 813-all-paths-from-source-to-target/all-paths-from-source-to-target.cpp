class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int> recst, vector<vector<int>>& ans,int node, int n) {
        if(node == n) {
            recst.push_back(n);
            ans.push_back(recst);
            return;
        }

        recst.push_back(node);

        for(auto adj : graph[node])
        {
            dfs(graph, recst, ans, adj, n);
        }

        recst.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> recst;
        vector<bool> vis(n, false);
        
        dfs(graph, recst, ans, 0, n-1);

        return ans;


    }
};