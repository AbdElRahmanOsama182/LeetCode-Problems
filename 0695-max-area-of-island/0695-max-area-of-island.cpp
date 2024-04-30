class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;
        if (vis[i][j] || grid[i][j] == 0)
            return 0;
        vis[i][j] = true;
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            ans += dfs(i + dx[k], j + dy[k], grid);
        }
        return 1 + ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1)
                    ans= max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};