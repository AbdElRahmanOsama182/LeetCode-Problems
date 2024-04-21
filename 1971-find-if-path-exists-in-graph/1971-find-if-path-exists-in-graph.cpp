class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for (auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(source,adj,vis);
        return vis[destination];
    }

    void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis) {
        if (vis[v]) return;
        vis[v] = true;
        for (auto u:adj[v]) {
            if(!vis[u])
                dfs(u,adj,vis);
        }
    }
};