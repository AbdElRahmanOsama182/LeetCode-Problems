class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i%3 == 2) continue;
            ans += cost[i];
        }
        return ans;
    }
};