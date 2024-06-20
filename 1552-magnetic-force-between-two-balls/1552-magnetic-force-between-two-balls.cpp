class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1, r = (position[n - 1] - position[0])/(m - 1) + 1;
        while (l < r) {
            int mid = l + (r - l)/2;
            int count = 1, prev = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - prev >= mid) {
                    count++;
                    prev = position[i];
                }
            }
            if (count >= m)
                l = mid + 1;
            else
                r = mid;
        }
        return l - 1;
    }
};