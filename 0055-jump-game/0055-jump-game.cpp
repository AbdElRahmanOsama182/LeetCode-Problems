class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        if (nums[0] == 0) return false;
        int lastZero = -1;
        for (int i = n - 2; i >= 0; i--){
            if (nums[i] == 0)
                lastZero = max(lastZero, i);
            else if (lastZero != -1 && nums[i] + i > lastZero)
                lastZero = -1;
        }
        return lastZero == -1;
    }
};