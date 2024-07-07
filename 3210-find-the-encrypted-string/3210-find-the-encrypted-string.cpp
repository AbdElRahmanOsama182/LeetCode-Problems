class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        k %= n;
        string res = s;
        for (int i = 0; i < n; i++)
            res[i] = s[(i + k) % n];
        return res;
    }
};