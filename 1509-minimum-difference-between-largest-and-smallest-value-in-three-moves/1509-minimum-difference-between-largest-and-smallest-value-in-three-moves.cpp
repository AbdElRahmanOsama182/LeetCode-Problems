class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= 3; i++)
            res = min(res, nums[n - 4 + i] - nums[i]);
        return res;
    }
};