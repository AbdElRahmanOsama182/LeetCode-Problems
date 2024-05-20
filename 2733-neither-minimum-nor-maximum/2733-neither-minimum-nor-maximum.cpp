class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mx) {
                if (mx != mn) return mx;
                mx = nums[i];
            }
            if (nums[i] < mn) {
                if (mx != mn) return mn;
                mn = nums[i];
            }
        }
        return -1;
    }
};