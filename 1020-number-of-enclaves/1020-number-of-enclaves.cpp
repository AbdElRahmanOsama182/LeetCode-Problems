class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++){
            dfs(grid, i, 0);
            dfs(grid, i, m-1);
        }
        for (int i = 0; i < m; i++){
            dfs(grid, 0, i);
            dfs(grid, n-1, i);
        }        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    ans++;
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++){
            dfs(grid, i+dir[k], j+dir[k+1]);
        }
    }
};