class Solution {
public:
    int dp[38] = {0};    
    int tribonacci(int n) {
        if (dp[n] != 0) return dp[n];
        if (n < 2)  return dp[n] = n;
        if (n == 2) return dp[n] = 1;
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};