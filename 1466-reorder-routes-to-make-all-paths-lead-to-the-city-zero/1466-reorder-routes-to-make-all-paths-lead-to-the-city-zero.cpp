class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& graph, int v, int p, int& ans){
        for(auto u: graph[v]){
            if (u.first == p) continue;
            ans += u.second;
            dfs(graph, u.first, v, ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto c: connections){
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }
        int ans = 0;
        dfs(graph, 0, -1, ans);
        return ans;
    }
};