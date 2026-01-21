class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for (long i = 1; i <= n; i*= 10) {
            long d = i * 10;
            ans += (n / d) * i + min(i, max(n%d-i+1, 0L));
        }
        return ans;
    }
};