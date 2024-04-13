class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int st = 1, l = 0, r = n-1, t = 0, b = n-1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        while(st <= n*n){
            for(int i = l; i <= r; i++)
                ans[t][i] = st++;
            t++;
            for(int i = t; i <= b; i++)
                ans[i][r] = st++;
            r--;
            for(int i = r; i >= l; i--)
                ans[b][i] = st++;
            b--;
            for(int i = b; i >= t; i--)
                ans[i][l] = st++;
            l++;
        }
        return ans;
    }
};