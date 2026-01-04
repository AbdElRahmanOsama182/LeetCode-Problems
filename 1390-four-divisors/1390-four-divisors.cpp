class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int& n : nums) {
            int cnt = 0, p, q;
            for (int i = 2; i*i <= n; i++) {
                if (n%i) continue;
                int j = n / i;
                if (i == j) cnt++;
                else {
                    cnt += 2;
                    p = i, q = j;
                }
                if (cnt > 2) break;
            }
            if (cnt == 2) ans += n + 1 + p + q;
        }
        return ans;
    }
};