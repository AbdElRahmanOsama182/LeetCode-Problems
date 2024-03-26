class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n > m) return false;
        int i = 0, j = 0;
        while (i < n && j < m){
            if (s[i] == t[j++])
                i++;
        }
        return i == n;
    }
};