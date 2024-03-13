class Solution {
public:
    int myAtoi(string s) {
        bool neg = false, skip = false;
        long long ans = 0;
        for(auto i : s){
            if (i == ' ' && !skip) continue;
            if (i == '-' && !skip) {
                neg = true, skip = true;
                continue;
            }
            if (i == '+' && !skip) {
                skip = true;
                continue;
            }
            if (i >= '0' && i <= '9'){
                ans = ans*10 + (i-'0');
                if (ans > INT_MAX) return neg ? INT_MIN : INT_MAX;
                skip = true;
            }
            else break;
        }
        return neg ? -ans : ans;
    }
};