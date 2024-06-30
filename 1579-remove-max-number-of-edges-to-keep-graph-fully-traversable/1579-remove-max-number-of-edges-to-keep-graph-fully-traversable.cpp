class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        count = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                swap(rootX, rootY);
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
            count--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    bool isSingle() {
        return count == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        });
        int added = 0;
        for (auto& edge : edges) {
            int type = edge[0], u = edge[1] - 1, v = edge[2] - 1;
            if (type == 3) {
                if (!alice.connected(u, v) || !bob.connected(u, v)) {
                    alice.unite(u, v);
                    bob.unite(u, v);
                    added++;
                }
            }
            else if (type == 1) {
                if (!alice.connected(u, v)) {
                    alice.unite(u, v);
                    added++;
                }
            }
            else {
                if (!bob.connected(u, v)) {
                    bob.unite(u, v);
                    added++;
                }
            }
        }
        return alice.isSingle() && bob.isSingle() ? edges.size() - added : -1;
    }
};