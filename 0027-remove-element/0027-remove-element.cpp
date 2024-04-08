class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == val)  nums[i] = 101, cnt++;
        }
        sort(nums.begin(), nums.end());
        return n - cnt;
    }
};