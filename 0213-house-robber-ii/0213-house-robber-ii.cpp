class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int op1 = robber(nums, 0, n - 1);
        int op2 = robber(nums, 1, n);
        return max(op1, op2);
    }
    int robber(vector<int>& nums, int st, int ed) {
        int op1 = 0, op2 = 0, curr = 0;
        for (int i = st; i < ed; i++) {
            curr = max(op1 + nums[i], op2);
            op1 = op2;
            op2 = curr;
        }
        return curr;
    }
};