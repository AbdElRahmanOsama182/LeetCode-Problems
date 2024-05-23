class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, 0, path, paths);
        return paths;
    }

    void dfs(vector<vector<int>>& graph, int u, vector<int>& path, vector<vector<int>>& paths){
        path.push_back(u);
        if (u == graph.size() - 1)
            paths.push_back(path);
        else 
            for (int v : graph[u])
                dfs(graph, v, path, paths);
        path.pop_back();
    }        
};