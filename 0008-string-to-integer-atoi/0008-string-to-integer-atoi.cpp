class Solution {
public:
    int myAtoi(string s) {
        bool neg = false, skipSpaces = true;
        long ans = 0;
        for (char c : s) {
            if (c == ' ' && skipSpaces) continue;
            if (c =='-' && skipSpaces) {
                neg = true;
                skipSpaces = false;
            }
            else if (c =='+' && skipSpaces) {
                skipSpaces = false;
            }
            else if (c >= '0' && c <= '9') {
                ans = ans * 10 + (c - '0');
                if (ans > INT_MAX) return neg? INT_MIN : INT_MAX;
            }
            else break;
        }
        return neg? -ans : ans;
    }
};