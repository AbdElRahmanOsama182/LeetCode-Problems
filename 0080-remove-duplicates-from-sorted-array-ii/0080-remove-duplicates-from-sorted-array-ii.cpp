class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), st = 1, en = 1, cnt = 1;
        while(en < n){
            if (nums[en] == nums[st-1]){
                cnt++;
                if (cnt <= 2)
                    nums[st++] = nums[en++];
                else
                    en++;
            }
            else{
                cnt = 1;
                nums[st++] = nums[en++];
            }
        }
        return st;
    }
};