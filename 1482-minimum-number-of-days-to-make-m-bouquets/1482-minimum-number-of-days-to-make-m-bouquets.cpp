class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long)m * k) return -1;
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            int bouquets = 0, flowers = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] > mid) 
                    flowers = 0;
                else if (++flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            if (bouquets < m) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};