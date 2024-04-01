class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long score = 0, sum = 0;
        int n = nums1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end(), greater<>());
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < k-1; i++){
            sum += v[i].second;
            pq.push(v[i].second);
        }
        for (int i = k-1; i < n; i++){
            sum += v[i].second;
            pq.push(v[i].second);
            score = max(score, sum*v[i].first);
            sum -= pq.top();
            pq.pop();
        }
        return score;
    }
};
