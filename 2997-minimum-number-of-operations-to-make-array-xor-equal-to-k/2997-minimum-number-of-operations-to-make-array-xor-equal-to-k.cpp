class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr = k;
        for (auto& i : nums) xr ^= i;
        int ans = 0;
        while (xr != 0) {
            if (xr & 1) ans++;
            xr >>= 1;
        }
        return ans;
    }
};