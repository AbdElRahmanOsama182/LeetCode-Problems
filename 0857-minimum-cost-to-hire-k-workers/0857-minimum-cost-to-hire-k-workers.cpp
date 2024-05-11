class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++){
            ratio.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        sort(ratio.begin(), ratio.end());
        double ans = DBL_MAX, sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++){
            sum += ratio[i].second;
            pq.push(ratio[i].second);
            if (pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k){
                ans = min(ans, sum*ratio[i].first);
            }
        }
        return ans;
    }
};