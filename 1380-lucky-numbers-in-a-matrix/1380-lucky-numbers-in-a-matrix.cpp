class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int rowMinMax = INT_MIN, colMinMax = INT_MAX;
        for (int i = 0; i < n; i++) {
            int rowMin = INT_MAX;
            for (int j = 0; j < m; j++)
                rowMin = min(rowMin, matrix[i][j]);
            rowMinMax = max(rowMinMax, rowMin);
        }
        for (int j = 0; j < m; j++) {
            int colMax = INT_MIN;
            for (int i = 0; i < n; i++)
                colMax = max(colMax, matrix[i][j]);
            colMinMax = min(colMinMax, colMax);
        }
        if (rowMinMax == colMinMax)
            return {rowMinMax};
        return {};
    }
};