class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int st = 0, ed = nums.size() - 1;

        while (st < ed) {
            if (nums[st] >= 0 || nums[ed] <= 0)
                break;
            int diff = nums[ed] + nums[st];
            if (diff == 0) return nums[ed];
            if (diff < 0) st++;
            else ed--;
        }
        return -1;
    }
};