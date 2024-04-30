class Solution {
public:
    bool isPerfectSquare(int num) {
        int st = 0, ed = num, mid;
        while (st <= ed) {
            mid = st + (ed - st) / 2;
            long long sq = (long long) mid * mid;
            if (sq == num) return true;
            if (sq > num) ed = mid - 1;
            else st = mid + 1;
        }
        return ed*ed == num;
    }
};