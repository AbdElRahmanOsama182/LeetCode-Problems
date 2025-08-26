class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mxDag = 0, mxArea = 0, currDag, currArea;
        for (auto &v : dimensions) {
            currDag = v[0]*v[0] + v[1]*v[1];
            currArea = v[0]*v[1];
            if (currDag > mxDag)
                mxDag = currDag, mxArea = currArea;
            else if (currDag == mxDag)
                mxArea = max(currArea, mxArea);
        }
        return mxArea;
    }
};