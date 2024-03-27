class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++) mp[grid[i]]++;
        int ans = 0;
        vector<int> temp(n);
        for (int j = 0; j < n; j++){
            for (int i = 0; i < n; i++) temp[i] = grid[i][j];
            ans += mp[temp];
        }
        return ans;   
    }
};