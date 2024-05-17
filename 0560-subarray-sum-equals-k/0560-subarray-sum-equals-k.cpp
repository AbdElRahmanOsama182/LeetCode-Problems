class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for (int num : nums) {
            sum += num;
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;        
    }
};