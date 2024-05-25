class Solution {
public:
    bool checkString(string s) {
        int n = s.size(), lastA = -1, firstB = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') lastA = i;
            else if (s[i] == 'b') firstB = i;
            if (lastA > firstB) return false;
        }
        return true;
    }
};