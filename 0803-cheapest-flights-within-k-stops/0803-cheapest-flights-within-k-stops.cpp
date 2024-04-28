class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> dist2(dist);
            for (auto f : flights) {
                if (dist[f[0]] == INT_MAX) continue;
                dist2[f[1]] = min(dist2[f[1]], dist[f[0]] + f[2]);
            }
            dist = dist2;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

