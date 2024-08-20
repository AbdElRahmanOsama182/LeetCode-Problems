class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> suffix(n+1);
        for (int i = n-1; i >= 0; i--) 
            suffix[i] = suffix[i+1] + piles[i];
        for (int i = 0; i <= n; i++) 
            dp[i][n] = suffix[i];
        for (int i = n-1; i >= 0; i--)
            for (int m = n-1; m >= 1; m--)
                for (int x = 1; x <= 2*m && i+x <= n; x++) 
                    dp[i][m] = max(dp[i][m], suffix[i] - dp[i+x][max(m, x)]);
        return dp[0][1];
    }
};