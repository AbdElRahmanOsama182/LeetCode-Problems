class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        string ans = "";
        for (char c : order) {
            while (cnt[c - 'a']) ans += c, cnt[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i]) ans += (char)('a' + i), cnt[i]--;
        }
        return ans;
    }
};