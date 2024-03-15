class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size(), e = 0, o = 1;
        while(e<n && o<n){
            while (e < n && (nums[e] & 1) == 0) e += 2;
            while (o < n && (nums[o] & 1) == 1) o += 2;
            if (e < n && o < n) {
                swap(nums[e], nums[o]);
                e+=2, o+=2;
            }
        }
        return nums;
    }
};
