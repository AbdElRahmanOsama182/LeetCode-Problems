struct DSU {
    int n, components;
    vector<int> p, sz;
    unordered_set<int> nodes;
    DSU(int n) {
        this->n = n;
        p.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; ++i) p[i] = i, sz[i] = 1;
        components = 0;
    }

    int find(int x) {
        if (p[x] == x) {
            if (nodes.find(x) == nodes.end()) {
                nodes.insert(x);
                components++;
            }
            return x;
        }
        return p[x] = find(p[x]); // Path compression
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v); // Small to Large
        p[v] = u;
        sz[u] += sz[v];
        components--;
        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int OFFSET = 1e4 + 1;
        DSU dsu(2*OFFSET);
        for (auto &stone : stones)
            dsu.join(stone[0], stone[1] + OFFSET);
        return stones.size() - dsu.components;
    }
};