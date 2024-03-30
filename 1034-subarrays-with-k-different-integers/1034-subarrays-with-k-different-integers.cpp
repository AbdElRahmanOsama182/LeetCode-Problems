class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> freq(n+1, 0);
        int l = 0, r = 0, cnt = 0;
        while (r < n){
            if (++freq[nums[r++]] == 1) 
                k--;
            while (k < 0){
                if (--freq[nums[l++]] == 0)  
                    k++;
                cnt = 0;
            }
            if (k == 0){
                while (freq[nums[l]] > 1){
                    cnt++;
                    freq[nums[l++]]--;
                }
                ans += cnt + 1;
            }
        }
        return ans;
    }
};