class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        long long ans = 1;
        for(int i = 1; i < n; i++){
            if (nums[i] != nums[i-1]){
                dp[i] = dp[i-1] + 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};