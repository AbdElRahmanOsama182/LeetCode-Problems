class Solution {
public:

    int getMin(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return INT_MAX;
        }
        return matrix[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) 
                matrix[i][j] += min(min(getMin(matrix, i - 1, j - 1), getMin(matrix, i - 1, j)), getMin(matrix, i - 1, j + 1));
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
    
};