class Solution {
public:
    int minSwaps(vector<int>& nums) {
        return min(minSwaps(nums, 0), minSwaps(nums, 1));
    }

    int minSwaps(vector<int>& nums, int num) {
        int n = nums.size();
        int cnt = 0;
        for (int &i : nums) 
            if (i == num) 
                cnt++;
        if (cnt == 0 || cnt == n) 
            return 0;
        int l = 0, r = 0, mx = 0, curr = 0;
        while (r < cnt)
            if (nums[r++] == num) 
                curr++;
        mx = curr;
        while (r < n) {
            if (nums[r++] == num) 
                curr++;
            if (nums[l++] == num) 
                curr--;
            mx = max(mx, curr);
        }
        return cnt - mx;
    }
};