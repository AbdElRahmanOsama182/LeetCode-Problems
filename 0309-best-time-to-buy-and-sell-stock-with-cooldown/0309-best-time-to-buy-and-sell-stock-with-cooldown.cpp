class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        dp[0][0] = 0; // Rest
        dp[1][0] = -prices[0]; // Buy
        dp[2][0] = 0; // Sell
        for (int i = 1; i < n; i++){
            dp[0][i] = max(dp[0][i-1], dp[2][i-1]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
            dp[2][i] = dp[1][i-1] + prices[i];
        }
        return max(dp[0][n-1], dp[2][n-1]);
    }
};