class Solution {
public:
    vector<vector<int>> efforts;
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        efforts = vector<vector<int>> (n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0, {0, 0}});
        efforts[0][0] = 0;
        while(!pq.empty()) {
            auto curr = pq.top().second;
            int effort = -pq.top().first;
            pq.pop();
            int x = curr.first, y = curr.second;
            if (efforts[x][y] > effort) continue;
            if (x == n - 1 && y == m - 1) return effort;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int newEffort = max(efforts[x][y], abs(heights[x][y] - heights[nx][ny]));
                if (newEffort < efforts[nx][ny]) {
                    efforts[nx][ny] = newEffort;
                    pq.push({-newEffort, {nx, ny}});
                }
            }
        }
        return efforts[n-1][m-1];
    }
};