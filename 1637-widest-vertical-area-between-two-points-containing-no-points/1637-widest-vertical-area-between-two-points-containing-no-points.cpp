class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int maxWidth = 0;
        for (int i = 1; i < points.size(); i++)
            maxWidth = max(maxWidth, points[i][0] - points[i-1][0]);
        return maxWidth;
    }
};