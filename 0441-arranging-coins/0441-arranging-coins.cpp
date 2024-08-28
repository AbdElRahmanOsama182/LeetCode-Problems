class Solution {
public:
    int arrangeCoins(int n) {
        int start = 1, end = n, mid, ans = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (check(mid, n)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    bool check(int mid, int n) {
        return ((long)mid * (mid + 1) / 2) <= n;
    }
};