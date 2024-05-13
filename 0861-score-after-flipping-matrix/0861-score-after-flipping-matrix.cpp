class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int score = n * (1 << (m - 1));
        for (int i = 1; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += (grid[j][i] == grid[j][0]);
            }
            score += max(cnt, n - cnt) * (1 << (m - 1 - i));
        }
        return score;
    }
};