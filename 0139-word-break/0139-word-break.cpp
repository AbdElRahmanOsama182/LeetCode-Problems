class Solution {
public:

    int dp[305];

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        return solve(s, wordDict, 0, s.size());
    }

    bool solve(string s, vector<string>& wordDict, int st, int en){
        if (st == en) return true;
        if (dp[st] != -1) return dp[st];
        for (auto word: wordDict){
            if (s.substr(st, word.size()) == word){
                if (solve(s, wordDict, st+word.size(), en)) 
                    return dp[st] = 1;
            }
        }
        return dp[st] = 0;
    }

};