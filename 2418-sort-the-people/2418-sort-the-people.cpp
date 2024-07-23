class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idxs(n);
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&heights](int a, int b) { 
            return heights[a] > heights[b];
        });
        vector<string> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = names[idxs[i]];
        }
        return sorted;
    }
};