class Solution {
public:

    int solve(vector<vector<int>>& dp, string &s, int i, int j) {
        if (i>j) return 0;
        if (i==j) {
            dp[i][j] = 1;
            return 1;
        }
        if (dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = 0;
        if (j - i == 1) {
            if (s[i] == s[j]) {
                dp[i][j] = 1;
            }
            return dp[i][j];
        }
        if (s[i] == s[j] && solve(dp, s, i + 1, j - 1) == 1) {
            dp[i][j] = 1;
        }
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                solve(dp, s, i, j);
                if (dp[i][j] == 1 && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};