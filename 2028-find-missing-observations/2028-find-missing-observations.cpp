class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        for (int i = 0; i < m; i++)
            sum -= rolls[i];
        if (sum < n || sum > 6 * n)
            return {};
        vector<int> missing(n);
        for (int i = n - 1; i >= 0; i--) {
            missing[i] = min(6, sum - i);
            sum -= missing[i];
        }
        return missing;
    }
};