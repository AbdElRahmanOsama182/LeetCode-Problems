class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxGold = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] != 0){
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));
                }
            }
        }
        return maxGold;
    }

    vector<int> dir = {0, 1, 0, -1, 0};
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) 
            return 0;
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxGold = 0;
        for (int d = 0; d < 4; d++)
            maxGold = max(maxGold, dfs(grid, i + dir[d], j + dir[d + 1], n, m));
        grid[i][j] = gold;
        return gold + maxGold;
    }
};