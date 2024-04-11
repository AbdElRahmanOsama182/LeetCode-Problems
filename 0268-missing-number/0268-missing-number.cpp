class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= i ^ nums[i];
        return ans ^ n;
    }

    int missingNumberMath(vector<int>& nums) {
        return (nums.size()*(nums.size()+1))/2 - accumulate(nums.begin(), nums.end(), 0);
    }
};