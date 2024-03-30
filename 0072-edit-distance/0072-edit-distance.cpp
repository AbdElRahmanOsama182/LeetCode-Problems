class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, 0, 0);        
    }
    int solve(string &word1, string &word2, int i, int j){
        if (i == n) return m-j;
        if (j == m) return n-i;
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) 
            return dp[i][j] = solve(word1, word2, i+1, j+1); // no operation needed
        int insert = 1 + solve(word1, word2, i, j+1);
        int remove = 1 + solve(word1, word2, i+1, j);
        int replace = 1 + solve(word1, word2, i+1, j+1);
        return dp[i][j] = min({insert, remove, replace});
    }
};