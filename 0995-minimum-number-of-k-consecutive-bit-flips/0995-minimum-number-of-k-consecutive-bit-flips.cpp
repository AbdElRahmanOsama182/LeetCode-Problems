class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, flip = 0;
        vector<int> isFlipped(n);
        for (int i = 0; i < n; i++) {
            if (i >= k)
                flip ^= isFlipped[i - k];
            if (flip ^ nums[i] == 0) {
                if (i + k > n)
                    return -1;
                isFlipped[i] = 1;
                flip ^= 1;
                res++;
            }
        }
        return res;
    }
};