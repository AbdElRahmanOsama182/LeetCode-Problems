class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, st = 0, zi = 0;
        bool zero = false;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0 && zero){
                ans = max(ans, i - st - 1);
                st = zi+1;       
                zi=i;   
            }
            else if (nums[i] == 0){
                zero = true;
                zi = i;
            }
        }
        ans = max(ans, n - st - 1);
        return ans;
    }
};