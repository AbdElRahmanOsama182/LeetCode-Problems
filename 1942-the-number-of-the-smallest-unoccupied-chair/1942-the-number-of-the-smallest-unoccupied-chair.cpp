class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> s(n), e(n);
        vector<int> ch(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            s[i] = {times[i][0], i};
            e[i] = {times[i][1], i};
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int i = 0, j = 0;
        while(i < n) {
            if (s[i].first <= e[j].first) {
                if (pq.empty()) 
                    ch[s[i].second] = i;
                else {
                    ch[s[i].second] = pq.top();
                    pq.pop();
                }
                if (s[i].second == targetFriend) 
                    return ch[s[i].second];
                ++i;
            }
            else 
                pq.push(ch[e[j++].second]);
        }
        return -1;
    }
};