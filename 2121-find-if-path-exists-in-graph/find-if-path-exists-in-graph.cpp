class Solution {
public:
    int parent[1000000];
    int size[1000000];

    int find_set(int i)
    {
        if(parent[i] == i) return i;
        return parent[i] = find_set(parent[i]);
    }

    void union_by_size(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if(a != b)
        {
            if(size[a] < size[b]) swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            union_by_size(u,v);
        }

        if(find_set(source) == find_set(destination)) return true;
        return false;
    }
};