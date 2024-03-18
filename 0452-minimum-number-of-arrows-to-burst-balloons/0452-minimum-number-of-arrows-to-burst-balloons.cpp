class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int n = points.size(), arrows = 1, end = points[0][1];
        for (int i = 1; i < n; i++)
            if (points[i][0] > end)
                arrows++, end = points[i][1];
            else
                end = min(end, points[i][1]);
        return arrows;
    }
};