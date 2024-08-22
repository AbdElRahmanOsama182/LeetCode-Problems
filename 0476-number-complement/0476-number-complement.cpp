class Solution {
public:
    int findComplement(int num) {
        int n = 0, x = num;
        while (x) {
            x >>= 1;
            n++;
        }
        return num ^ ((1LL << n) - 1);
    }
};