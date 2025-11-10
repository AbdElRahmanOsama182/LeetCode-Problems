class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        vector<int> pre(n, 1), suff(n, 1);
        for (int i=1; i < n; i++) 
            if (nums[i]>=nums[i-1]) pre[i]+=pre[i-1];
        for (int i=n-2; i > -1; i--) 
            if (nums[i]<=nums[i+1]) suff[i]+=suff[i+1];
        if (pre[n-1] == n) return n;
        int ans = pre[n-1]+1;
        for (int i=1; i<n-1;i++) {
            ans = max(pre[i]+1, ans);
            if (nums[i+1] >= nums[i-1]) ans = max(ans, pre[i-1]+1+suff[i+1]);
        }
        return ans;
    }
};