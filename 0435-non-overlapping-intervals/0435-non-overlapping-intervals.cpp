class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), keep = 1, last = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        for (int i = 1; i < n; i++){
            if (intervals[i][0] >= intervals[last][1]){
                keep++;
                last = i;
            }
        }
        return n - keep;
    }
};