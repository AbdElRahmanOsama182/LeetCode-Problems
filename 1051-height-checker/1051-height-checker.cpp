class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        int cnt = 0;
        for (int i = 0; i < heights.size(); i++) 
            if (heights[i] != sortedHeights[i]) cnt++;
        return cnt;
    }
};