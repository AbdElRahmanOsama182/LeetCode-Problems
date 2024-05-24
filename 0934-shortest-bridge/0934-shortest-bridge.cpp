class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> firstIsland;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    dfs(grid, i, j, firstIsland);
                    break;
                }
            }
        }
        return bfs(grid, firstIsland) - 1;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& firstIsland){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 2;
        firstIsland.push({i, j});
        for (int k = 0; k < 4; k++)
            dfs(grid, i + dir[k], j + dir[k + 1], firstIsland);
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& firstIsland){
        int flips = 0;
        while (!firstIsland.empty()){
            int sz = firstIsland.size();
            for (int i = 0; i < sz; i++){
                auto [x, y] = firstIsland.front();
                firstIsland.pop();
                for (int k = 0; k < 4; k++){
                    int nx = x + dir[k], ny = y + dir[k + 1];
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 2) continue;
                    if (grid[nx][ny] == 1) return flips;
                    grid[nx][ny] = 2;
                    firstIsland.push({nx, ny});
                }
            }
            flips++;
        }
        return flips;
    }
};