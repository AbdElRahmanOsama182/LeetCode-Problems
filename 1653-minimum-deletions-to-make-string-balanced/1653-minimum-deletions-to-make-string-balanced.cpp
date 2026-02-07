class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int> (n+1, 0));
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                dp[0][i+1] = dp[0][i];
                dp[1][i+1] = min(dp[1][i] + 1, dp[0][i]);
            }
            else {
                dp[0][i+1] = dp[0][i] + 1;
                dp[1][i+1] = min(dp[1][i], dp[0][i]);
            }
        }
        return min(dp[0][n], dp[1][n]);
    }
};