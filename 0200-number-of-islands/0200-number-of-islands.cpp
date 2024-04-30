class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};

    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0) return;
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(x + d[i], y + d[i + 1], grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};