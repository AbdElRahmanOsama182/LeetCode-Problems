class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {profit[i], difficulty[i]};
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int ans = 0;
        for (int i = m - 1; i >= 0 && jobs.size(); i--) {
            while (jobs.size() && jobs.back().second > worker[i])
                jobs.pop_back();
            if (jobs.size())
                ans += jobs.back().first;
        }
        return ans;        
    }
};