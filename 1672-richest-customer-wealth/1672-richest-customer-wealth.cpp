class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (vector<int> account : accounts) 
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        return maxWealth;
    }
};