class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0, mask = 1, first = 0;
        for (auto& num : nums) Xor ^= num;
        while (!(Xor & mask)) mask <<= 1;
        for (auto& num : nums)
            if (num & mask)
                 first ^= num;
        return {first, first ^ Xor};
    }
};