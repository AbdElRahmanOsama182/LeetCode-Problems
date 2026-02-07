class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                        greater<pair<int, int>>>
            pq;
        sort(events.begin(), events.end());
        int mx2 = 0, mx1 = 0;
        for (auto& e: events) {
            while (pq.size() && pq.top().first < e[0]) {
                mx1 = max(mx1, pq.top().second);
                pq.pop();
            }
            mx2 = max(mx2, mx1 + e[2]);
            pq.push({e[1], e[2]});
        }
        return mx2;
    }
};