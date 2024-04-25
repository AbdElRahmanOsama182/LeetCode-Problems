class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';
            int longest = 0;
            for (int j = 0; j < 26; j++) {
                if (abs(curr - j) <= k) {
                    longest = max(longest, dp[j]);
                }
            }
            dp[curr] = max(dp[curr], longest + 1);
            ans = max(ans, dp[curr]);
        }
        return ans;
    }
};