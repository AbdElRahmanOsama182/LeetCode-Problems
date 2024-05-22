class Solution {
public:
    vector<vector<bool>> isPalindrome;
    int minCut(string s) {
        int n = s.size();
        isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        buildPalindrome(s);
        vector<int> dp(n, -1);
        return minCut(s, 0, dp) - 1;
    }

    void buildPalindrome(string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
            isPalindrome[i][i] = true;
        for (int i = 0; i < n - 1; i++)
            isPalindrome[i][i + 1] = s[i] == s[i + 1];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && s[i] == s[j];
            }
        }
    }

    int minCut(string& s, int start, vector<int>& dp) {
        if (start == s.size())
            return 0;
        if (dp[start] != -1)
            return dp[start];
        int minCuts = INT_MAX;
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome[start][i]) {
                minCuts = min(minCuts, 1 + minCut(s, i + 1, dp));
            }
        }
        return dp[start] = minCuts;
    }
};
