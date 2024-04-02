class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int l = 0, r = costs.size()-1, n = costs.size(), lCost = 0, rCost = 0;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pqL, pqR;
        while (k--){
            while (pqL.size() < candidates && l <= r)
                pqL.push(costs[l++]);
            while (pqR.size() < candidates && r >= l)
                pqR.push(costs[r--]);
            lCost = (pqL.empty()) ? INT_MAX : pqL.top();
            rCost = (pqR.empty()) ? INT_MAX : pqR.top();
            if (lCost <= rCost){
                ans += lCost;
                pqL.pop();
            }
            else{
                ans += rCost;
                pqR.pop();
            }
        }
        return ans;
    }
};