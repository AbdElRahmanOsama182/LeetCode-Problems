class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int st = 0, sum = 0, ans = 0;
        vector<bool> vis(1e4+1, false);
        for (int i = 0; i < nums.size(); i++) {
            while(vis[nums[i]]) {
                vis[nums[st]] = false;
                sum -= nums[st++];
            }
            vis[nums[i]] = true;
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};