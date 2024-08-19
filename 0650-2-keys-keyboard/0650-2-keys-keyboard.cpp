class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for (int i = 1; i <= n; i++) 
            for (int j = 2; j <= n; j++) 
                if (i*j <= n)
                    dp[i*j] = min(dp[i*j], dp[i]+j);
        return dp[n];
    }
};