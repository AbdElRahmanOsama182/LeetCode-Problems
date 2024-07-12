class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), gain = 0;
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        int cntA = 0, cntB = 0;
        for (char c : s) {
            if (c == 'a') cntA++;
            else if (c == 'b') {
                if (cntA > 0) {
                    cntA--;
                    gain += x;
                }
                else cntB++;
            }
            else {
                gain += min(cntA, cntB) * y;
                cntA = cntB = 0;
            }
        }
        return gain + min(cntA, cntB) * y;
    }
};