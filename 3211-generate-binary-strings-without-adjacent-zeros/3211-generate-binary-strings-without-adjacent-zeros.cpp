class Solution {
public:
    vector<string> validStrings(int n) {
        if (n == 1) return {"0", "1"};
        vector<string> res;
        vector<string> prev = validStrings(n - 1);
        for (string s : prev) {
            if (s[0] == '1') {
                res.push_back("0" + s);
            }
            res.push_back("1" + s);
        }
        return res;
    }
};