class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        return dijkstra(adj, start_node, end_node);
    }

    double dijkstra(vector<vector<pair<int, double>>>& adj, int start_node, int end_node) {
        vector<double> probs(adj.size(), 0);
        probs[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            pq.pop();
            if (u == end_node) return prob;
            for (auto &[v, p] : adj[u]) {
                if (probs[v] < prob * p) {
                    probs[v] = prob * p;
                    pq.push({probs[v], v});
                }
            }
        }
        return 0;
    }
};