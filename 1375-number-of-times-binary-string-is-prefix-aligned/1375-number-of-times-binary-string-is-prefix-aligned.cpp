class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size(), l = 0, r = 0, ans=1;
        vector<bool> f(n+2, false);
        f[0] = true;
        for (int i = 0; i < n-1; i++) {
            f[flips[i]] = true;
            r = max(r, flips[i]);
            while(f[l+1]) ++l;
            if (l == r) ans++;         
        }
        return ans;
    }
};