class Solution {
public:

    int solve(vector<vector<int>> &dp, string &s1, string &s2, int i, int j) {
        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = solve(dp, s1, s2, i+1, j+1);
        return dp[i][j] = 1 + min({solve(dp, s1, s2, i+1, j), solve(dp, s1, s2, i, j+1), solve(dp, s1, s2, i+1, j+1)});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return solve(dp, word1, word2, 0, 0);
    }
};