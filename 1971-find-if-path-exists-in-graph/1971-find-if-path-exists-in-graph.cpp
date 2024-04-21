class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> p(n), sz(n,1);
        for (int i = 0; i < n; i++)
            p[i] = i;
        for (auto e:edges)
            join(e[0],e[1],p,sz);
        return find(source,p) == find(destination,p);
    }

    int find(int x, vector<int>& p) {
        return p[x] = (p[x]==x)?x:find(p[x],p);
    }
    void join(int u, int v, vector<int>& p, vector<int>& sz) {
        u = find(u, p);
        v = find(v, p);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u,v);
        p[v] = u;
        sz[u]+=sz[v];
    }
};
