class Solution {
public:
    bool isExit(int &x, int &y, int &n, int &m){
        return x == 0 || x == n - 1 || y == 0 || y == m - 1;
    }

    bool isValid(int &x, int &y, int &n, int &m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size(), level = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dir){
                    int nx = x + dx, ny = y + dy;
                    if (isValid(nx, ny, n, m) && maze[nx][ny] == '.' && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        if (isExit(nx, ny, n, m)) return level + 1;
                    }
                    
                }
            }
            level++;
        }
        return -1;
    }
};