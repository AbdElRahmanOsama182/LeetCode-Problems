class Solution {
public:
    int N;
    vector<int> ans, count;
    vector<vector<int>> adj;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count = vector<int> (n, 1);
        ans = vector<int> (n, 0);
        adj = vector<vector<int>> (n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    void dfs(int node, int parent) {
        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : adj[node]) {
            if (child != parent) {
                ans[child] = ans[node] + N - 2 * count[child];
                dfs2(child, node);
            }
        }
    }
};