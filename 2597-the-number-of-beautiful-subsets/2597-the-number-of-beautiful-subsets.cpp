class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        return backtrack(nums, 0, k, freq) - 1;
    }
    int backtrack(vector<int>& nums, int idx, int k, unordered_map<int, int>& freq){
        if (idx == nums.size())
            return 1;
        int ans = 0;
        if (!freq[nums[idx] - k]){
            freq[nums[idx]]++;
            ans += backtrack(nums, idx + 1, k, freq);
            freq[nums[idx]]--;
        }
        ans += backtrack(nums, idx + 1, k, freq);
        return ans;
    }   
};