class Solution {
public:
    int numSteps(string s) {
        int ans = 0, carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            int bit = s[i] - '0';
            if (bit ^ carry)
                ans ++, carry = 1;
            ans++;
        }
        if (carry) ans++;
        return ans;
    }
};