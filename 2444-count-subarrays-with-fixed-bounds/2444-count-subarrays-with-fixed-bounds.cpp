class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0, st = -1, lastMn = -1, lastMx = -1;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] < minK || nums[i] > maxK)
                st = i;
            if (nums[i] == minK)
                lastMn = i;
            if (nums[i] == maxK)
                lastMx = i;
            ans += max(0ll, min(lastMn, lastMx) - st);
        }
        return ans;
    }
};