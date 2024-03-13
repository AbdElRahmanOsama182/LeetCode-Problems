class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev;
        for (int i = 0; i < numRows; i++) {
            vector<int> cur(i+1, 1);
            for (int j = 1; j < i; j++) {
                cur[j]=prev[j-1]+prev[j];
            }
            res.push_back(cur);
            prev = cur;
        }
        return res;
    }
};