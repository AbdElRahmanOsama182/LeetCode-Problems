class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (mid <= r) {
            if (nums[mid] == 0) 
                swap(nums[l++], nums[mid++]); 
            else if (nums[mid] == 2) 
                swap(nums[mid], nums[r--]);
            else 
                mid++;
        }
    }
};