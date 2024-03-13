class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = triangle[0][0];
        for (int i=1; i<triangle.size(); i++){
            int mn = INT_MAX;
            for (int j=0; j<triangle[i].size(); j++){
                if (j==0) triangle[i][j] += triangle[i-1][j];
                else if (j==triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
                mn = min(mn,triangle[i][j]);
            }
            ans = mn;
        }
    return ans;
    }
};