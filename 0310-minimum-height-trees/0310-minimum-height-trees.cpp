class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto& e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if(degree[i] == 1) q.push(i);
        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; i++) {
                int front = q.front();
                q.pop();
                for (int x:adj[front]) {
                    degree[x]--;
                    if (degree[x] == 1) q.push(x);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};