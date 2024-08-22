class Solution {
public:
    int findComplement(int num) {
        return (unsigned)~0 >> __builtin_clz(num) ^ num;
    }
};