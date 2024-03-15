class Solution {
public:

    bool dfs(int u, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& safe){
        vis[u] = 1;
        for(auto v:graph[u]){
            if(!vis[v]){
                if(!dfs(v,graph,vis,safe)) return 0;
            }
            else if(!safe[v]) return 0;
        }
        return safe[u] = 1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(),0), safe(graph.size(),0);
        vector<int> ans;

        for(int i=0; i<graph.size(); i++){
            if(!vis[i]) dfs(i,graph,vis,safe);
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};