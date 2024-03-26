class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int start = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if (nums[i] < start) continue;
            if (nums[i] == start) start++;
            else return start;
        }
        return start;
    }
};