class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combs;
        vector<int> comb;
        backtrack(combs, comb, 1, n, k);
        return combs;
    }

    void backtrack(vector<vector<int>>& combs, vector<int>& comb, int st, int n, int k) {
        if (k == 0) {
            combs.push_back(comb);
            return;
        }
        for (int i = st; i <= n - k + 1; i++) {
            comb.push_back(i);
            backtrack(combs, comb, i + 1, n, k - 1);
            comb.pop_back();
        }
    }
};