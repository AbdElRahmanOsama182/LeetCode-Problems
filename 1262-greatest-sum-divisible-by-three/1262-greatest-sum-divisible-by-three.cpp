class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for (int &x : nums) {
            vector<int> curr = dp;
            for (int i = 0; i < 3; i++)
                curr[(i+x%3)%3] = max(curr[(i+x%3)%3], dp[i]+x);
            dp = move(curr);
        }
        return dp[0];
    }
};