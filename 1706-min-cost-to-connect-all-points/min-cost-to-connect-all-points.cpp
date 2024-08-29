class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    void unionBySize(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }   
    }

    int MST(vector<pair<int,pair<int,int>>>& edges, int n) {
        int ans = 0;
        sort(edges.begin(), edges.end());
        for(auto edge : edges) {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if(find(u) != find(v)) {
                unionBySize(u,v);
                ans += w;
            }
        }

        return ans;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        for(int i=0 ; i < n; ++i) {
            for(int j=0; j < n; ++j) {
                if(i == j) continue;
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({w,{i,j}});
            }
        }

        parent = vector<int> (n);
        size = vector<int> (n, 1);

        for(int i=0; i < n; i++) parent[i] = i;
        return MST(edges, n);

    }
};