class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> sum(n);
        sum[0] = chalk[0];
        for (int i = 1; i < n; i++) 
            sum[i] = sum[i-1] + chalk[i];
        k %= sum[n-1];
        int l = 0, r = n-1, mid, ans = -1;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (sum[mid] <= k) 
                l = mid+1;
            else {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};