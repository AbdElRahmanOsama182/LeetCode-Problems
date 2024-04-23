class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        if ( n == 1) return 1;
        vector<int> dp(n+2, 0);
        dp[n-1] = (s[n-1] == '0')?0:1;
        dp[n] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] =='0') continue;
            dp[i] += dp[i+1];
            int x = (s[i]-'0')*10+(s[i+1]-'0');
            if (x < 27) dp[i] += dp[i+2];
        }
        return dp[0];
    }
};