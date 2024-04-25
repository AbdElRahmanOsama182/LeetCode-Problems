class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int st = 0, ed = mat.size() - 1, mid, mx, l, r;
        while (st <= ed) {
            mid = st + (ed - st) / 2;
            mx = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            l = (mid - 1 > -1)? mat[mid - 1][mx] : -1;
            r = (mid + 1 < mat[mid].size())? mat[mid + 1][mx] : -1;
            if (mat[mid][mx] > l && mat[mid][mx] > r) {
                return {mid, mx};
            }
            else if (mat[mid][mx] < l) {
               ed = mid - 1;
            }
            else {
                st = mid + 1; 
            }
        }
        return {-1, -1};
    }
};