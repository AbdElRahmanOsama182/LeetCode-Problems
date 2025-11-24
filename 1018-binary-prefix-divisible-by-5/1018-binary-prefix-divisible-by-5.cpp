class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), curr = 0;
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            curr = (curr << 1) + (nums[i]<<1);
            curr%=5;
            ans[i] = !(curr%5);
        }
        return ans;
    }
};