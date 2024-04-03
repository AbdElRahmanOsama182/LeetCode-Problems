class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), mx = *max_element(piles.begin(), piles.end());
        if (n == h) return mx;
        int l = 1, r = mx, mid, cnt;
        while (l < r){
            mid = l + (r-l)/2;
            cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += (piles[i]+mid-1)/mid;
            if (cnt > h) l = mid+1;
            else r = mid;
        }
        return l;
    }
};