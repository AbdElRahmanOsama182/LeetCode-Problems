class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, st = 0;
        bool zero = false;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0 && zero){
                ans = max(ans, i - st - 1);
                while (nums[st] != 0) st++;
                st++;                    
            }
            else if (nums[i] == 0){
                zero = true;
            }
        }
        ans = max(ans, n - st - 1);
        return ans;
    }
};