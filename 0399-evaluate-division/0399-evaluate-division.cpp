class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, string a, string b, unordered_map<string, bool>& visited){
        if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) return -1;
        if (a == b) return 1;
        visited[a] = true;
        for (auto p: graph[a]){
            if (!visited[p.first]){
                double res = dfs(graph, p.first, b, visited);
                if (res != -1) return res * p.second;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        vector<double> ans;
        for (auto q: queries){
            unordered_map<string, bool> visited;
            double res = dfs(graph, q[0], q[1], visited);
            ans.push_back(res);
        }
        return ans;
    }
};