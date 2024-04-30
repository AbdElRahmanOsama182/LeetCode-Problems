class Solution {
public:
    int mySqrt(int x) {
        int st = 0, ed = x, mid;
        while (st <= ed) {
            mid = st + (ed - st) / 2;
            long long sq = (long long) mid * mid;
            if (sq == x) return mid;
            if (sq > x) ed = mid - 1;
            else st = mid + 1;
        }
        return ed;
    }
};