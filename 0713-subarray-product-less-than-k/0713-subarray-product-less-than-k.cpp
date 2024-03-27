class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
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