class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1, 1);
        int two = 0, three = 0, five = 0;
        while (dp.size() < n) {
            dp.push_back(min({2*dp[two], 3*dp[three], 5*dp[five]}));
            if (dp.back() == 2*dp[two]) two++;
            if (dp.back() == 3*dp[three]) three++;
            if (dp.back() == 5*dp[five]) five++;
        }
        return dp.back();
    }
};