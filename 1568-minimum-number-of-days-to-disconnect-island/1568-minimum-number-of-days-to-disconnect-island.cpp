class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (numIslands(grid) != 1) return 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (numIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    int numIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    islands++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]) return;
        vis[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k], y = j + dir[k+1];
            dfs(grid, vis, x, y);
        }
    }
};