class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n =  nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) continue;
            int lsb_zero = (~nums[i]) & (nums[i] + 1);
            ans[i] = nums[i] & ~(lsb_zero >> 1);
            cout << nums[i] << " " << ans[i] << endl;
        }
        return ans;
    }
};