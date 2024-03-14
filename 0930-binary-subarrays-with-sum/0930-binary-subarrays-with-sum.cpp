class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> cnt(nums.size() + 1);
        cnt[0] = 1;
        int ans = 0, sum = 0;
        for (int x : nums) {
            sum += x;
            if (sum >= goal) ans += cnt[sum - goal];
            cnt[sum]++;
        }
        return ans;
    }
};