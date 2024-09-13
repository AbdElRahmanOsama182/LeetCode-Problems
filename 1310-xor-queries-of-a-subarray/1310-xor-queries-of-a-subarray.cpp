class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); i++) 
            arr[i] ^= arr[i-1];
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) 
            ans[i] = arr[queries[i][1]] ^ (queries[i][0] ? arr[queries[i][0]-1] : 0);
        return ans;
    }
};