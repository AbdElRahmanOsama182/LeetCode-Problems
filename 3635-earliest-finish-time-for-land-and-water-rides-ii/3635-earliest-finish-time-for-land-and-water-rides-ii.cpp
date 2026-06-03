class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }

    int solve(vector<int>& st1, vector<int>& d1, vector<int>& st2, vector<int>& d2) {
        int t1 = INT_MAX, t2 = INT_MAX;
        for (int i = 0; i < st1.size(); i++) 
            t1 = min(t1, st1[i]+d1[i]);
        for (int i = 0; i < st2.size(); i++) 
            t2 = min(t2, max(t1, st2[i]) + d2[i]);
        return t2;
    }
};