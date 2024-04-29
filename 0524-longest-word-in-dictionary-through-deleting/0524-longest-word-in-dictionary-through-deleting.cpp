class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int n = s.size();
        for (auto& d : dictionary) {
            int i = 0, j = 0, m = d.size();
            if (m > n) continue;
            while (i < n && j < m) {
                if (s[i] == d[j]) {
                    j++;
                }
                i++;
            }
            if (j == m && (ans.size() < m || (ans.size() == m && d < ans))) {
                ans = d;
            }
        }
        return ans;
    }
};