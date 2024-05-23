class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n == 1) return 0;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            if (manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID, adj, informTime);
    }

    int dfs(int headID, vector<vector<int>>& adj, vector<int>& informTime){
        if (adj[headID].size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < adj[headID].size(); i++){
            res = max(res, dfs(adj[headID][i], adj, informTime) + informTime[headID]);
        }
        return res;
    }
};