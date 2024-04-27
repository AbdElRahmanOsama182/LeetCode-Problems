class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<int> dp(n, 0);
        for (int i = m - 1; i >= 0; i--) {
            vector<int> next_dp(n, INT_MAX);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (ring[k] == key[i]) {
                        int mn = abs(j - k);
                        mn = min(mn, n - mn);
                        next_dp[j] = min(next_dp[j], mn+1+dp[k]);
                    }
                }
            }
            dp = next_dp;
        }
        return dp[0];
    }
};