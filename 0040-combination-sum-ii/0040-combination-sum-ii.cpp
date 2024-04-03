class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void comb(vector<int>& candidates, int target, int index, vector<int>& v){
        if (target == 0){
            ans.push_back(v);
            return;
        }
        if (index == n || target < 0) return;
        for (int i = index; i < n; i++){
            if (i > index && candidates[i] == candidates[i-1]) continue;
            v.push_back(candidates[i]);
            comb(candidates, target-candidates[i], i+1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        comb(candidates, target, 0, v);
        return ans;
    }
};