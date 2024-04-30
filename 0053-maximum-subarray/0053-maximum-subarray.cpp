class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (int i : nums) {
            sum = max(i, sum + i);
            ans = max(ans, sum);
        }
        return ans;
    }
};