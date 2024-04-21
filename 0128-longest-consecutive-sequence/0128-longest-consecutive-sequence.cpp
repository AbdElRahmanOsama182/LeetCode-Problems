class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int ans = 1, cnt = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i]==nums[i-1]) continue;
            if (nums[i] == nums[i-1]+1) cnt++;
            else {
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
        return max(ans,cnt);
    }
};