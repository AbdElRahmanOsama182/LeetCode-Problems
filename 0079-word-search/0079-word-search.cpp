class Solution {
public:
    vector<vector<int>> vis;
    string word;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    bool dfs(vector<vector<char>>& board, int i, int j, int idx) {
        if (idx == word.size()) return true;
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] != word[idx]) return false;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) 
            if (dfs(board, i+dx[k], j+dy[k], idx+1)) return true;
        vis[i][j] = 0;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        this->word = word;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (dfs(board, i, j, 0)) return true;
        return false;
    }
};