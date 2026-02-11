class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i <0 || i == grid.size() ||
            j < 0 || j == grid[0].size() ||
            !grid[i][j]) return 0;
        int ans = 1;
        grid[i][j] = 0;
        for (int d = 0; d < 4; d++)
            ans += dfs(i+dir[d], j+dir[d+1], grid);
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                ans = max(ans, dfs(i, j, grid));
        return ans;
    }
};