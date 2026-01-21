class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int c = 0;
            for (int& n : nums)
                if (n & (1 << i))
                    c++;
            ans |= (c%3) << i;
        }
        return ans;
    }
};