class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        long double l = 0, r = 2e9, mid;
        for (int k = 0; k < 100; k++) {
            mid = (l+r) / 2.0;
            long double a1 = 0, a2 = 0;
            for (int i = 0; i < n; i++) {
                if (squares[i][1] >= mid)
                    a2 += 1.0 * squares[i][2] * squares[i][2];
                else if (squares[i][1] + squares[i][2] <= mid)
                    a1 += 1.0 * squares[i][2] * squares[i][2];
                else {
                    a1 += 1.0 * squares[i][2] * (mid - squares[i][1]);
                    a2 += 1.0 * squares[i][2] * (squares[i][1] + squares[i][2] - mid);
                }
            }
            if (a1 >= a2) r = mid;
            else l = mid; 
        }
        return l;
    }
};