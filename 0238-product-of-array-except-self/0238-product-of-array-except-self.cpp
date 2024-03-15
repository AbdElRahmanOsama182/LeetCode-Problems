class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), p = 1, zero = 0;
        for (auto i : nums) {
            if (i == 0) zero++;
            else p *= i;
        }
        vector<int> ans(n, 0);
        if (zero > 1) return ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) ans[i] = p;
            else if (zero == 1) ans[i] = 0;
            else ans[i] = p / nums[i];
        }
        return ans;
    }
};