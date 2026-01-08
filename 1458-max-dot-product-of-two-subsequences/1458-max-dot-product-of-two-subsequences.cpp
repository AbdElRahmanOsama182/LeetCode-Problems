class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<long>> dp(n+1, vector<long> (m+1, INT_MIN));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i+1][j+1] = nums1[i] * nums2[j];
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j+1] + dp[i][j]);
                dp[i+1][j+1] = max({dp[i+1][j+1],  dp[i+1][j],  dp[i][j+1]});
            }
        }
        return dp[n][m];
    }
};