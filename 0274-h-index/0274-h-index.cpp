class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), h, ans = 0;
        sort(citations.begin(), citations.end());
        int l = 0, r = n-1, mid;
        while (l <= r){
            mid = l + (r-l)/2;
            h = n-mid;
            if (citations[mid] < n-mid)
                l = mid+1;
            else
                r = mid-1;
        }
        return n-l;
    }
};