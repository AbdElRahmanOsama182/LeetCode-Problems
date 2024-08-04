class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod = 1e9+7;
        long long ans = sumOfFirstKElements(nums, n, right) % mod;
        ans = (ans - sumOfFirstKElements(nums, n, left-1) + mod) % mod;
        return ans;
    }

    pair<int, long long> countAndSum(vector<int>& nums, int n, int x) {
        int count = 0;
        long long sum = 0, longestSub = 0, allSubs = 0;
        for (int l = 0, r = 0; r < n; r++) {
            longestSub += nums[r];
            allSubs += nums[r] * (r-l+1);
            while (longestSub > x) {
                allSubs -= longestSub;
                longestSub -= nums[l++];
            }
            count += r-l+1;
            sum += allSubs;
        }
        return {count, sum};
    }

    long long sumOfFirstKElements(vector<int>& nums, int n, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (countAndSum(nums, n, mid).first >= k) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        auto[count, sum] = countAndSum(nums, n, l);
        return sum - l * (count - k);
    }
};