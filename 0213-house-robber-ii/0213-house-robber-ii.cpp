class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(ropHelper(nums,0,n-1),ropHelper(nums,1,n));
    }
    int ropHelper(vector<int>& nums, int st, int ed) {
        int prev = 0, prev2 = 0, curr = 0;
        for (int i = st; i < ed; i++) {
            curr = max(prev,prev2+nums[i]);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};