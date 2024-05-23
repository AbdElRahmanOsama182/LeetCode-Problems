class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        unordered_map<int, int> restrictedMap;
        for(auto r : restricted) restrictedMap[r] = 1;
        for(auto e : edges) {
            if (restrictedMap[e[0]] || restrictedMap[e[1]]) continue;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if (restrictedMap[0]) return 0;
        return dfs(0, -1, adj);
    }

    int dfs(int u, int p, vector<vector<int>>& adj) {
        int vis = 1;
        for(auto v : adj[u]) {
            if (v == p) continue;
            vis += dfs(v, u, adj);
        }
        return vis;
    }
};