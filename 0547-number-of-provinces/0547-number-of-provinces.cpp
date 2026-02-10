class Solution {
public:

    void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& vis) {
        if (vis[u]) return;
        vis[u] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (vis[i] || !isConnected[u][i]) continue;
            dfs(i, isConnected, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            ++ans;
            dfs(i, isConnected, vis);
        }
        return ans;
    }
};