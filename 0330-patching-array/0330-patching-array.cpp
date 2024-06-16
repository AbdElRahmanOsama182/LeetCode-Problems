class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long patches = 0, i = 0, missing = 1;
        while (missing <= n) {
            if (i < nums.size() && nums[i] <= missing) 
                missing += nums[i++];
            else 
                missing += missing, patches++;
        }
        return patches;
    }
};