class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> stk;
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });
        for (int i : indices) {
            if (directions[i] == 'R')
                stk.push(i);
            else {
                while (!stk.empty() && healths[stk.top()] < healths[i]) {
                    healths[i]--;
                    healths[stk.top()] = 0;
                    stk.pop();
                }
                if (!stk.empty()) {
                    if (healths[stk.top()] == healths[i]) {
                        healths[stk.top()] = 0;
                        stk.pop();
                    }
                    else 
                        healths[stk.top()]--;
                    healths[i] = 0;
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (healths[i] > 0)
                res.push_back(healths[i]);
        return res;                
    }
};