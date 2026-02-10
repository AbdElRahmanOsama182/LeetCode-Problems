class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dir = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = true;
        int lvl = 0;
        while (q.size()) {
            int sz = q.size();
            lvl++;
            for (int i = 0; i < sz; i++) {
                auto[x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dir[d], ny = y + dir[d+1];
                    if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
                    if (vis[nx][ny] || maze[nx][ny] == '+') continue;
                    if (nx == 0 || nx == n-1 || ny == 0|| ny == m-1) return lvl;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};