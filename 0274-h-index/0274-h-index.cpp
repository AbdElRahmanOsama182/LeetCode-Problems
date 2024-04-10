class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), h, ans = 0;
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            h = min(citations[i], n - i);
            ans = max(ans, h);
        }
        return ans;
    }
};