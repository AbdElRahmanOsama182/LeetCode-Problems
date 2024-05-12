class Solution {
public:
    struct edge{
        int u, v, w;
        edge(int u, int v, int w): u(u), v(v), w(w){}
        bool operator<(const edge& e) const{
            return w > e.w;
        }
    };
    vector<int> parent, size;
    int find(int u){
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<edge> pq;
        parent.resize(points.size());
        size.resize(points.size(), 1);
        for (int i = 0; i < points.size(); i++){
            parent[i] = i;
        }
        int n = points.size();
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push(edge(i, j, w));
            }
        }
        int ans = 0;
        while (!pq.empty()){
            edge e = pq.top();
            pq.pop();
            if (find(e.u) != find(e.v)){
                join(e.u, e.v);
                ans += e.w;
            }
        }
        return ans;
    }
};