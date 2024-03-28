class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), st = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
            if (mp[nums[i]] > k) {
                ans = max(ans, i - st);
                while (mp[nums[i]] > k){
                    mp[nums[st]]--;
                    st++;
                }
            }
        }
        ans = max(ans, n - st);
        return ans;
    }
};