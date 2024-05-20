class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int Or = 0;
        for (int& num : nums) Or |= num;
        int ans = 0, pwr = 1, mul = pow(2, nums.size() - 1);
        while (Or != 0) {
            if (1 & Or) ans += mul*pwr;
            Or >>= 1;
            pwr *= 2;
        }
        return ans;
    }
};