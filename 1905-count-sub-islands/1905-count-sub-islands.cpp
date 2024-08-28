class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int id = 1;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid1[i][j] == 1)
                    dfs(grid1, i, j, ++id);
        int ans = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid2[i][j] == 1)
                    ans += isSub(grid2, grid1, i, j, grid1[i][j]) & (grid1[i][j] > 1);
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int &id) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) 
            return;
        grid[i][j] = id;
        for (int k = 0; k < 4; k++) 
            dfs(grid, i+dir[k], j+dir[k+1], id);
    }

    bool isSub(vector<vector<int>>& grid, vector<vector<int>>& island, int i, int j, int &id) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) 
            return true;
        bool ans = island[i][j] == id;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) 
            ans &= isSub(grid, island, i+dir[k], j+dir[k+1], id);
        return ans;
    }
};