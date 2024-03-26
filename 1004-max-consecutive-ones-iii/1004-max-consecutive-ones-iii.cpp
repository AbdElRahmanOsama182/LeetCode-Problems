class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), st = 0, ans = 0, cnt = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0) cnt++;
            while (cnt > k){
                if (nums[st] == 0) cnt--;
                st++;
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};