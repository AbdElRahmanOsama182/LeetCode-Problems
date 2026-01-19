class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                pre[i+1][j+1] = mat[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j];
        int l = 1, r = min(n, m), ans = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (check(pre, mid, threshold)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }

    bool check(vector<vector<int>>& pre, int len, int th) {
        int n = pre.size(), m = pre[0].size();
        for (int i = 1; i < n - len + 1; i++) {
            int ii = i + len - 1;
            for (int j = 1; j < m - len + 1; j++) {
                int jj = j + len - 1;
                int sum = pre[ii][jj] - pre[i-1][jj] - pre[ii][j-1] + pre[i-1][j-1];
                if (sum <= th) return true;
            }
        }
        return false;
    }
};