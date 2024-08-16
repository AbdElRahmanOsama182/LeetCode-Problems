class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), ans = INT_MIN;
        int mn = arrays[0][0], mx = arrays[0].back();
        for (int i = 1; i < n; i++) {
            ans = max(ans, abs(arrays[i].back() - mn));
            ans = max(ans, abs(mx - arrays[i][0]));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }
        return ans;
    }
};