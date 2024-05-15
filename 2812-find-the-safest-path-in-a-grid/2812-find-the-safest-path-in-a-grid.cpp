class Solution {
public:

    vector<vector<int>> dist;
    vector<vector<bool>> visited;
    vector<int> dir = {0, 1, 0, -1, 0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        bfs(grid);
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()){
            auto [d, p] = pq.top();
            pq.pop();
            auto [x, y] = p;
            if (x == n - 1 && y == n - 1) return d;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (int i = 0; i < 4; i++){
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]){
                    pq.push({min(d, dist[nx][ny]), {nx, ny}});
                }
            }
        }
        return -1;
    }

    void bfs(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
        int levels = 0;
        while (!q.empty()){
            int sz = q.size();
            levels++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++){
                    int nx = x + dir[i], ny = y + dir[i + 1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == INT_MAX){
                        dist[nx][ny] = levels;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};