class Solution {
public:
    int numTilings(int n) {
        int MOD = 1e9+7;
        if (n < 3) return n;
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for (int i = 4; i <= n; i++){
            dp[i] = (2*dp[i-1])%MOD + dp[i-3]%MOD;
            dp[i] %= MOD;
        }
        return dp[n];
    }
};