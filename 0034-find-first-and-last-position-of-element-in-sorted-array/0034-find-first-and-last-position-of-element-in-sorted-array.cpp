class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                int st = mid, ed = mid;
                while (st >= 0 && nums[st] == target) st--;
                while (ed < n && nums[ed] == target) ed++;
                return {st + 1, ed - 1};
            }
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return {-1, -1};
    }
};