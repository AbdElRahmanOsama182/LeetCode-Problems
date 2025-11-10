class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size(), ans = 0, l, r;
        vector<int> occ(2002, 0);
        for (int& i : arr2) 
            ++occ[i+1001];
        for (int i = 1; i < 2002; i++) occ[i]+=occ[i-1];
        for (int& i : arr1) {
            l = max(-1000, i-d);
            r = min(1000, i+d);
            if (occ[r+1001]-occ[l+1000]==0)
                ans++;
        }
        return ans;
    }
};