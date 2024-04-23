class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int st = 1, ed = x, mid;
        while (st <= ed) {
            mid = st + (ed-st)/2;
            long long sq = static_cast<long long>(mid)*mid;
            if (sq > x)
                ed = mid - 1;
            else if (sq == x)
                return mid;
            else 
                st = mid + 1;
        }
        return ed;
    }
};