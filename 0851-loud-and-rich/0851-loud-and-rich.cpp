class Solution {
public:

    int dfs(vector<vector<int>>& graph, vector<int>& quiet, vector<int>& ans, int i){
        if (ans[i] != -1) return ans[i];
        ans[i] = i;
        for (auto& j : graph[i]){
            int k = dfs(graph, quiet, ans, j);
            if (quiet[k] < quiet[ans[i]]) ans[i] = k;
        }
        return ans[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> graph(quiet.size());
        vector<int> ans(quiet.size(), -1);
        for (auto& r : richer) graph[r[1]].push_back(r[0]);
        for (int i = 0; i < quiet.size(); i++) dfs(graph, quiet, ans, i);
        return ans;
    }
};