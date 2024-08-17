class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points[0].size();
        vector<vector<long long>> dp(2, vector<long long>(m, 0));
        int cur = 1;
        for (auto &row : points) {
            long long mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx - 1, dp[(cur^1)][i]);
                dp[cur][i] = mx;
            }
            mx = 0;
            for (int i = m-1; i >= 0; i--) {
                mx = max(mx - 1, dp[cur^1][i]);
                dp[cur][i] = max(dp[cur][i], mx) + row[i];
            }
            cur ^= 1;
        }
        return *max_element(dp[(cur^1)].begin(), dp[(cur^1)].end());
    }
};