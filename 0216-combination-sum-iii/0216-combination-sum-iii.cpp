class Solution {
public:
    vector<vector<int>> ans;

    void comb(int num, int k, int n, vector<int>& v){
        if (n == 0 && k == 0){
            ans.push_back(v);
            return;
        }
        if (n < 0 || k < 0) return;
        if (num > 9) return;
        v.push_back(num);
        comb(num+1, k-1, n-num, v);
        v.pop_back();
        comb(num+1, k, n, v);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        comb(1, k, n, v);
        return ans;
    }
};