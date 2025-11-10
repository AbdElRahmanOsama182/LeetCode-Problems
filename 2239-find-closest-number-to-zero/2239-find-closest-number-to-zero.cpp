class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int l = INT_MIN+2, r = INT_MAX;
        for (int& x : nums) {
            if (x == 0) return 0;
            if (x > 0) r = min(r, x);
            if (x < 0) l = max(l, x);
        }
        if (-l < r) return l;
        return r;
    }
};