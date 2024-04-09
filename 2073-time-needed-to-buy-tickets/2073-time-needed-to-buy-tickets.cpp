class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), turns = tickets[k];
        int ans = turns;
        for (int i = 0; i < k; i++)
            ans += min(tickets[i], turns);
        for (int i = k + 1; i < n; i++)
            ans += min(tickets[i], turns - 1);
        return ans;
    }
};