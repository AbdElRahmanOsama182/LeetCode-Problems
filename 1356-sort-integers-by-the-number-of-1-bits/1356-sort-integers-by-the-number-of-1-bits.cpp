class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> dp(10001, 0);
        for(int i = 1; i <= 10000; i++){
            dp[i] = dp[i>>1] + (i&1);
        }
        sort(arr.begin(),arr.end(), [&](int a, int b){
            if (dp[a] == dp[b]) return a < b;
            return dp[a] < dp[b];
        });
        return arr;
    }
};