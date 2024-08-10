struct DSU {
    int n;
    vector<int> p, sz;

    DSU(int n) {
        this->n = n;
        p.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; ++i) p[i] = i, sz[i] = 1;
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]); // Path compression
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v); // Small to Large
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu((n + 1) * (n + 1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) 
                if (i == 0 || j == 0 || i == n || j == n) 
                    dsu.join(i * (n + 1) + j, 0);
        }
        int ans = 1, u, v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    u = i * (n + 1) + j + 1;
                    v = (i + 1) * (n + 1) + j;
                } else if (grid[i][j] == '\\') {
                    u = i * (n + 1) + j;
                    v = (i + 1) * (n + 1) + j + 1;
                } else {
                    continue;
                }
                if (!dsu.join(u, v)) 
                    ans++;
            }
        }
        return ans;
    }
};