class Solution {
public:
    int bitwiseComplement(int n) {
        return (unsigned)~0 >> __builtin_clz(max(n,1)) ^ n;
    }
};