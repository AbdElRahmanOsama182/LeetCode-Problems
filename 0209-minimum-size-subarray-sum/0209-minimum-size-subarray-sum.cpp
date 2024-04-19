class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MAX, st = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            while (sum >= target){
                ans = min(ans, i - st + 1);
                sum -= nums[st++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};