class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt=0, Oranges=0;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 0) continue;
                Oranges++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    cnt++;
                }
            }
        }
        if (Oranges == 0 || Oranges == cnt) return 0;
        int time = 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int j=0; j<4; j++){
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    cnt++;
                }
            }
            time++;
            if (cnt == Oranges) return time;
        }
        return -1;
    }
};