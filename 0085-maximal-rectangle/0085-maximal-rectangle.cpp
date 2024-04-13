class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0, h, w;
        vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
        for(int i=1; i<=n; i++){
            matrix[i-1].push_back('0');
            stack<int> s;
            for(int j=1; j<=m+1; j++){
                dp[i][j] = (matrix[i-1][j-1] == '1') ? dp[i-1][j] + 1 : 0;
                while (!s.empty() && dp[i][s.top()] > dp[i][j]){
                    h = dp[i][s.top()];
                    s.pop();
                    w = s.empty() ? j-1 : j-s.top()-1;
                    ans = max(ans, h*w);
                }
                s.push(j);
            }
        }
        return ans;
    }
};