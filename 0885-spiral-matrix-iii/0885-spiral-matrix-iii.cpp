class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<int> dir = {0, 1, 0, -1, 0};
        vector<vector<int>> ans;
        for (int len = 1, d = 0; ans.size() < rows * cols; ++len) {
            for (int i = 0; i < 2; ++i) {
                for (int k = 0; k < len; ++k) {
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                    }
                    rStart += dir[d], cStart += dir[d + 1];
                }
                d = (d + 1) % 4;
            }
        }
        return ans;
    }
};