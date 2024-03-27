class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        long long prod = 1;
        int cnt = 0, st = 0;
        for (int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            while (prod >= k)
                prod /= nums[st++];
            cnt += i - st + 1;
        }
        return cnt;
    }
    // with log & Binary Search
    int numSubarrayProductLessThanKLog(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int n = nums.size()+1, cnt = 0;
        vector<double> prefix(n, 0);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + log(nums[i-1]);
        double logk = log(k), eps = 1e-9;
        for (int i = 0; i < n; i++){
            int st = i+1, en = n;
            while (st < en){
                int mid = st + (en-st)/2;
                if (prefix[mid] - prefix[i] + eps < logk) st = mid+1;
                else en = mid;
            }
            cnt += st - i - 1;
        }
        return cnt;
    }
};