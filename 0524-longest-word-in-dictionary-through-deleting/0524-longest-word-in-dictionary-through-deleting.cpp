class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int n = s.size();
        for (auto& d : dictionary) {
            int i = 0, j = 0;
            int m = d.size();
            while (i < n && j < m) {
                if (s[i] == d[j]) i++, j++;
                else i++;
            }
            if (j == m && (m > ans.size() || (m == ans.size() && d < ans)))
                ans = d;
        }
        return ans;
    }
};