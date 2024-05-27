class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e5));
        for(int i=1; i<n; i++){
            dp[i][i+1] = 1;
            dp[i+1][i] = 1;
        }
        dp[x][y] = dp[y][x] = 1;
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        vector<int> ans(n, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (i != j){
                    ans[dp[i][j]-1]++;
                }
            }
        }
        return ans;
    }
};