class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n-2; i++)
            for (int j = 0; j < m-2; j++)
                if (isMagic(grid, i, j))
                    ans++;
        return ans;             
    }

    bool isMagic(vector<vector<int>>& grid, int x, int y) {
        string seq = "2943816729438167", seqRev = "7618349276183492";
        string s = "";
        vector<int> v = {0, 1, 2, 5, 8, 7, 6, 3};
        for (auto i : v)
            s += to_string(grid[x+i/3][y+i%3]);
        return (grid[x][y]%2 == 0) && (grid[x+1][y+1] == 5) && (seq.find(s) != string::npos || seqRev.find(s) != string::npos);
    }
};