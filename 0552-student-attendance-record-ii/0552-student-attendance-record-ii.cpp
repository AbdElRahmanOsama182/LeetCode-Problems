class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1e9+7;
        vector<vector<int>> cur(2, vector<int>(3, 0)), next(2, vector<int>(3, 0));
        cur[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int A = 0; A < 2; A++) {
                for (int L = 0; L < 3; L++) {
                    next[A][0] = (next[A][0] + cur[A][L]) % MOD;
                    if (A > 0) next[A][0] = (next[A][0] + cur[A - 1][L]) % MOD;
                    if (L > 0) next[A][L] = (next[A][L] + cur[A][L - 1]) % MOD;
                }
            }
            cur = next;
            next = vector<vector<int>>(2, vector<int>(3, 0));
        }
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                ans = (ans + cur[i][j]) % MOD;
            }
        }
        return ans;
    }
};