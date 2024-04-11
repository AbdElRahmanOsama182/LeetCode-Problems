class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0, cnt = 1;
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i-1])
                continue;
            if (nums[i] == nums[i-1]+1)
                cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};