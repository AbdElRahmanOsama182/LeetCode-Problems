class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, odd = 0;
        vector<int> count(n+1, 0);
        count[0] = 1;
        for (int i = 0; i < n; i++) {
            odd += nums[i] & 1;
            if (odd >= k) {
                ans += count[odd - k];
            }
            count[odd]++;
        }
        return ans;
    }
};