class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int wait = 0, time = 0;
        for (auto c : customers) {
            time = max(time, c[0]) + c[1];
            wait += time - c[0];
        }
        return (double)wait / n;
    }
};