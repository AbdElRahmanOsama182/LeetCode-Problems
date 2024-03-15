class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int freq[10005]={0};
        for (int i:nums) freq[i]++;
        int dp[10005]={0};
        dp[1]=freq[1];
        for (int i=2; i<10005; i++) {
            dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);
        }
        return dp[10004];
    }
};