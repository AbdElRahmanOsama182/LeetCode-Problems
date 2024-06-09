class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        vector<int> cnt(k);
        cnt[0] = 1;
        for (int num : nums) {
            sum = (sum + num % k + k) % k;
            ans += cnt[sum]++;
        }
        return ans;
    }
};