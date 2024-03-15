
    class Solution {
        public int[] sortArrayByParityII(int[] nums) {
            int n = nums.length, e = 0, o = 1;
            while (e < n && o < n) {
                while (e < n && (nums[e] & 1) == 0) e += 2;
                while (o < n && (nums[o] & 1) == 1) o += 2;
                if (e < n && o < n) {
                    int temp = nums[e];
                    nums[e] = nums[o];
                    nums[o] = temp;
                    e += 2;
                    o += 2;
                }
            }
            return nums;
        }
    }
