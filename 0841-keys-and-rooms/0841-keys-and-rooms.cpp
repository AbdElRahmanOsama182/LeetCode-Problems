class Solution {
public:

    void dfs(int u, vector<vector<int>>& rooms, vector<bool>& vis) {
        if (vis[u]) return;
        vis[u] = true;
        for (auto& v: rooms[u])
            if(!vis[v]) dfs(v, rooms, vis);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        for (int i = 1; i < n; i++)
            if(!vis[i]) return false;
        return true;
    }
};