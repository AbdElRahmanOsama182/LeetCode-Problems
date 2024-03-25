class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, freq(n+1, 0);
        for (int i = 0; i < n; i++){
            freq[nums[i]]++;
            if (freq[nums[i]] == 2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};