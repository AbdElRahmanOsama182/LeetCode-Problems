class Solution {
public:
    int strangePrinter(string s) {
        string t = "";
        t += s[0];
        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i-1]) t += s[i];
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                dp[i][j] = len;
                for (int k = i; k < j; k++) {
                    int temp = dp[i][k] + dp[k+1][j];
                    if (t[k] == t[j]) temp--;
                    dp[i][j] = min(dp[i][j], temp);
                }
            }
        }
        return dp[0][n-1];
    }
};